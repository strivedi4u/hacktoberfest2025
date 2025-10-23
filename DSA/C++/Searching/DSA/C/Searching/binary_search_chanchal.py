# LANGUAGE: Python
# AUTHOR: Chanchal Kuntal
# GITHUB: https://github.com/Chanchal-D

# 🎃 Hacktoberfest 2025 Contribution
# Topic: Binary Search Algorithm in Python

def binary_search(arr, target):
    """Perform binary search on a sorted list."""
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return f"Element {target} found at index {mid}"
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    return f"Element {target} not found in array"

# Example usage
if __name__ == "__main__":
    arr = [1, 3, 5, 7, 9, 11, 13]
    target = 7
    print(binary_search(arr, target))
