# defining the function to find maximum from a given tuple or list
def maximum(tuple):
    max = tuple[0]
    for i in tuple:
        max = i if i>max else max
    return max

# example
numbers = (5, 10, 18, 20, 16, 2)
max_num = maximum(numbers)
print("Maximum:", max_num)
