def sum_of_digits(number):
    # Convert the number to its absolute value (ignoring any negative sign)
    number = abs(number)
    
    # Initialize sum
    total = 0
    
    # Loop through each digit in the number
    while number > 0:
        # Get the last digit
        digit = number % 10
        # Add the digit to the total sum
        total += digit
        # Remove the last digit
        number = number // 10
    
    return total

num = int(input())
print(f"Sum of digits of {num} is: {sum_of_digits(num)}")