def second_largest(nums: list[int]):
    """
    Returns the second largest number in the list.
    If not found, returns None.
    """
    if len(nums) < 2:
        return None
    
    first = second = float('-inf')
    for num in nums:
        if num > first:
            second = first
            first = num
        elif first > num > second:
            second = num

    return second if second != float('-inf') else None

if __name__ == "__main__":
    test_cases = [
        [10, 5, 8, 20, 20],
        [5, 5, 5],
        [1],
        [7, 8, 9, 10]
    ]

    for lst in test_cases:
        print(f"List: {lst} -> Second Largest: {second_largest(lst)}")
