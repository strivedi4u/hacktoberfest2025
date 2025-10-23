def lengthOfLIS(nums):
    sub = []
    
    for num in nums:
        # Binary search manually
        left, right = 0, len(sub)
        while left < right:
            mid = (left + right) // 2
            if sub[mid] < num:
                left = mid + 1
            else:
                right = mid
        
        # If num is greater than all elements, append it
        if left == len(sub):
            sub.append(num)
        else:
            # Replace first element >= num
            sub[left] = num
    
    return len(sub)

# Example
nums = [10,9,2,5,3,7,101,18]
print(lengthOfLIS(nums))  # Output: 4
