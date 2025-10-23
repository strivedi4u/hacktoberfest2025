# Binary Search implementation in Python

def binary_search(arr, target):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2  # Find the middle index
        if arr[mid] == target:
            return mid  # Target found, return index
        elif arr[mid] < target:
            low = mid + 1  # Search the right half
        else:
            high = mid - 1  # Search the left half

    return -1  # Target not found

# Example usage
data = [2, 4, 6, 8, 10, 12, 14, 16, 18]
target = 10
result = binary_search(data, target)

if result != -1:
    print(f"Element {target} found at index {result}.")
else:
    print(f"Element {target} not found in the list.")
