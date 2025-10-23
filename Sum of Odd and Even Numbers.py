# define a function
def sum_of_odd_and_even(lst):

    # initialize the variables to store both sums
    odd_sum = 0
    even_sum = 0

    # loop through the list
    for item in lst:

        # if the item is even, add it to the even_sum
        if item % 2 == 0:
            even_sum += item

        # if the item is odd, add it to the odd_sum
        else:
            odd_sum += item

    # return both sums
    return odd_sum, even_sum


# call the function
lst = input().split()
int_list = [int(x) for x in lst]
result = sum_of_odd_and_even(int_list)
print(result)
