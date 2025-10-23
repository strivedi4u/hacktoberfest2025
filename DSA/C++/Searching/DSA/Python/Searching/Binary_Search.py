from typing import List
def binarySearch(arr: List[int], x: int)-> int:
    arr.sort()
    low = 0
    high = len(arr) - 1
    while(low <= high):
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1
    return -1

arr = list()
size = int(input("Enter the size of the array: "))
for _ in range(size):
    data = int(input("Enter the data: "))
    arr.append(data)
key = int(input("Enter the value of key: "))
print(binarySearch(arr=arr, x=key))
