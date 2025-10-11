class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        start=0
        end=len(arr)-1
        mid=start+(end-start)//2

        while start < end:
            if arr[mid] < arr[mid + 1]:
                start = mid + 1
            else:
                end = mid
            mid=start+(end-start)//2
        return start 
