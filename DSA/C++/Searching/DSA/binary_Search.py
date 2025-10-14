# BinarySearch.py

def binary_search(arr, x):
    """
    Perform binary search on a sorted list 'arr' to find element 'x'.
    Returns the index if found, otherwise -1.
    """
    low, high = 0, len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1

    return -1


def main():
    print("=== Binary Search in Python ===")
    n = int(input("Enter number of elements: "))
    arr = list(map(int, input("Enter elements (sorted): ").split()))
    x = int(input("Enter element to search: "))

    result = binary_search(arr, x)

    if result != -1:
        print(f"Element found at index {result}")
    else:
        print("Element not found.")


if __name__ == "__main__":
    main()
