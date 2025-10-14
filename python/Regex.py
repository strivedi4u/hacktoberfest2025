#What are regular expressions in python .
#Regular expressions are a powerful tool for matching patterns in strings. 
#They can be used for a wide range of tasks, from simple string matching to complex text processing.


##Concept of regular expressions with example 

# import re library
import re

# Define a string
text = "Today is Wednesday, October 9, 2024 and here are the results:"

 # Define a pattern to match dates in the format "Month Day, Year"
pattern = r"\b(January|February|March|April|May|June|July|August|September|October|November|December)\s\d{1,2},\s\d{4}\b"

# Use the re.search function to find the first occurrence of the pattern in the text
match = re.search(pattern, text)

# If a match is found, print the matched text
if match:
    print("Matched date:", match.group())
else:
    print("No match found")

# Define a pattern to match email addresses
email_pattern = r"\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b"

# Use the re.findall function to find all occurrences of the pattern in the text
emails = re.findall(email_pattern, text)

# Print the matched email addresses
print("Matched email addresses:", emails)

# Define a pattern to match phone numbers in the format "XXX-XXX-XXXX"
phone_pattern = r"\b\d{3}-\d{3}-\d{4}\b"

# Use the re.sub function to replace all occurrences of the pattern in the text with a new string
new_text = re.sub(phone_pattern, "XXX-XXX-XXXX", text)

# Print modified text
print("Modified text:", new_text)

