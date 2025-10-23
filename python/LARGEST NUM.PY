def find_largest(numbers):
    # Initialize the largest number as the first element
    if not numbers:
        return None  # Return None if the list is empty
    largest = numbers[0]
    # Iterate through the list to find the largest number
    for num in numbers:
        if num > largest:
            largest = num
    return largest
