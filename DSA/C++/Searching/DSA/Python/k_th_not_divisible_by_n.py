"""
Problem Statement:
You are given two positive integers n and k. Print the k-th positive integer that is not divisible by n.

Example:
If n = 3 and k = 7, the numbers not divisible by 3 are: 1, 2, 4, 5, 7, 8, 10, 11, 13...
The 7th number among them is 10.

Input:
The first line contains an integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each test case consists of two positive integers n (2 ≤ n ≤ 10^9) and k (1 ≤ k ≤ 10^9).

Output:
For each test case, print the k-th positive integer that is not divisible by n.

Examples:
Input:
6
3 7
4 12
2 1000000000
7 97
1000000000 1000000000
2 1

Output:
10
15
1999999999
113
1000000001
1
"""

# Brute Force:

t = int(input())  # number of test cases

for _ in range(t):
    n, k = list(map(int, input().split()))  # read n (divisor) and k (kth non-divisible number)

    low = 1
    high = n * k  # upper bound: the kth non-divisible number must be <= n*k
    mid = 0

    # binary search to find kth number not divisible by n
    while low <= high: 
        mid = (low + high) // 2  # middle of current search range

        # count how many numbers from 1..mid are NOT divisible by n
        f = mid - (mid // n)  

        if f < k:
            # fewer than k numbers found → move right
            low = mid + 1  
        elif f > k:
            # more than k numbers found → move left
            high = mid - 1
        else:
            # exactly k numbers found
            # if mid itself is divisible by n, move one step left
            # because we want a number not divisible by n
            if mid % n == 0:
                mid -= 1
            break

    print(mid)  # print the kth number not divisible by n




