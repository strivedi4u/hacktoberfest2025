# This function checks if a given word is a palindrome.
# A palindrome reads the same forwards and backwards.
def is_palindrome(word):
    """
    Checks if the given word (string) is a palindrome.
    Returns True if it is a palindrome, False otherwise.
    """
    # Use slicing to reverse the string and compare it to the original
    # We convert to lowercase to handle case-insensitive palindromes (e.g., "Madam")
    return word.lower() == word.lower()[::-1]

# --- Example Usage ---

# 1. Define the words to test
# Note: The function converts the word to lowercase for case-insensitive checking
word1 = "level"
word2 = "Python"

# 2. Call the function to check if they are palindromes
result1 = is_palindrome(word1)
result2 = is_palindrome(word2)

# 3. Print the results
print(f"Word 1: '{word1}' is a palindrome: {result1}")
print(f"Word 2: '{word2}' is a palindrome: {result2}")

# Another example (case-insensitive check):
word3 = "Madam"
print(f"\nWord 3: '{word3}' is a palindrome: {is_palindrome(word3)}")
