def binary_search(arr, x):
    low = 0
    high = len(arr) - 1

    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1

    return -1


n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter elements: ").split()))
arr.sort()
x = int(input("Enter element to search: "))

result = binary_search(arr, x)
if result != -1:
    print(f"Element found at index {result}")
else:
    print("Element not found.")
