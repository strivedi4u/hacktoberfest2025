def twoSum(arr, target):
  
    # Create a set to store the elements
    s = set()

    for num in arr:
      
        # Calculate the complement that added to
        # num, equals the target
        complement = target - num

        # Check if the complement exists in the set
        if complement in s:
            return True

        # Add the current element to the set
        s.add(num)

    # If no pair is found
    return False

if __name__ == "__main__":
    arr = [0, -1, 2, -3, 1]
    target = -2
    if twoSum(arr, target):
        print("true")
    else:
        print("false")
