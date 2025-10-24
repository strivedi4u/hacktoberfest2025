class Solution:
    def lengthOfLIS(self, nums):
        sub = []
        for x in nums:
            l, r = 0, len(sub)
            while l < r:
                m = (l + r) // 2
                if sub[m] < x:
                    l = m + 1
                else:
                    r = m
            if l == len(sub):
                sub.append(x)
            else:
                sub[l] = x
        return len(sub)