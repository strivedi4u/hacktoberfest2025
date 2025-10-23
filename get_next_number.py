def get_next_number(n):
    """
    Calculates the sum of the square of the digits of the number n.
    """
    total_sum = 0
    while n > 0:
        digit = n % 10
        total_sum += digit * digit
        n //= 10
    return total_sum

def is_happy(n):
    """
    Checks if a given positive integer 'n' is a Happy Number.
    A number is happy if the sequence of sums of squares of its digits
    eventually reaches 1. It uses a set to detect cycles.
    
    Returns True if it is a happy number, False otherwise.
    """
    if n <= 0:
        return False

    # Use a set to detect if the number sequence enters a cycle
    seen_numbers = set()
    current = n

    while current != 1 and current not in seen_numbers:
        seen_numbers.add(current)
        current = get_next_number(current)

    # If the loop terminates because current == 1, it's a happy number
    return current == 1

# --- Example Usage ---

# 1. Define the numbers to test
# 19 is a Happy Number: 19 -> 82 -> 68 -> 100 -> 1
number1 = 19
# 2 is not a Happy Number (it gets stuck in the 4 -> 16 -> ... cycle)
number2 = 2

# 2. Call the function to check
result1 = is_happy(number1)
result2 = is_happy(number2)

# 3. Print the results
print(f"Number {number1} is a happy number: {result1}")
print(f"Number {number2} is a happy number: {result2}")

# Another example:
number3 = 7 # 7 is a Happy Number: 7 -> 49 -> 97 -> 130 -> 10 -> 1
print(f"\nNumber {number3} is a happy number: {is_happy(number3)}")
