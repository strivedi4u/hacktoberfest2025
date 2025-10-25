# creating a birthday countdown
import datetime
import time

def get_birth_day(name):
    print(f"Dear {name}❤️  your birthdate please😇")
    year = int(input("Year: "))
    month = int(input("Month: "))
    day = int(input("Day: "))
    return datetime.date(year, month, day)

print("-------------------------------------------------")
print("Welcome to this Special Program")
print("-------------------------------------------------")
name=input("Your good name please: ")
dob=get_birth_day(name)
current_date = datetime.date.today()
print("-------------------------------------------------\n")

# calculating the number of days left
if current_date.month < dob.month:
    next_birthday = datetime.date(current_date.year, dob.month, dob.day)

elif current_date.month == dob.month and current_date.day <= dob.day:
    next_birthday = datetime.date(current_date.year, dob.month, dob.day)

else:
    next_birthday = datetime.date(current_date.year + 1, dob.month, dob.day)

# getting the number of days left
days_left = next_birthday - current_date

# countdown
next_birthday_datetime = datetime.datetime.combine(next_birthday, datetime.datetime.min.time())
# (This was for testing how the end will look like)
#next_birthday_datetime = datetime.datetime(2025,1,31,11,26,10)

i = 0
while i <7:
    i+=1
    print("Starting the countdown","👀"*i, end="\r")
    time.sleep(0.5)
print("\n")
print("\U0001F973"*3)
print("-------------------------------------------------")

while days_left.days > 0 or days_left.seconds > 0:
    current_date = datetime.datetime.now()
    countdown = next_birthday_datetime - current_date
    if countdown.days<0:
        break
    days = countdown.days
    hours, remainder = divmod(countdown.seconds, 3600)
    minutes, seconds = divmod(remainder, 60)
    
    print("Time left:", days, "days", hours, "hours", minutes, "minutes", seconds, "seconds", end="\r")
#   print(f"{days} days    {hours}:{minutes}:{seconds}", end="\r")
    time.sleep(1)


print("\n-------------------------------------------------")
time.sleep(1)
print(f"Happy Birthday {name}🎁!")
print("😍"*7)
print("-------------------------------------------------")
y=input("")

