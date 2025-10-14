# prints to screen an array of strings by surrounding them in a frame
def program_header(elements):
	elements.insert(len(elements), "")
	elements.insert(0, "")
	longest = 0
	sep = "#"
	for elm in elements:
		if len(elm) > longest:
			longest = len(elm)
	print(sep * (longest + 4))
	for elm in elements:
		print(sep + " " + elm + " " * (longest - len(elm)) + " " + sep)
	print(sep * (longest + 4))


# saves an array of strings to the file in SAVE_FILE_PATH by appending a the array as a comma separated values line
def save_to_csv_file(elements, path):
	CSV_SEPARATOR = ";"
	out_file = open(path, "a")
	cs = ""
	for index, el in enumerate(elements):
		if index == len(elements) - 1:
			cs += el
		else:
			cs += el + CSV_SEPARATOR
	out_file.write(cs + "\n")
