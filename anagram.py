from collections import Counter

def count_anagram_subsequences(s, w_list):
    def is_anagram_subsequence(s, target):
        target_count = Counter(target)
        s_count = Counter(s)
        
        for char in target_count:
            if target_count[char] > s_count[char]:
                return False
        return True

    count = 0
    for w in w_list:
        if is_anagram_subsequence(s, w):
            count += 1
    return count

s = input().strip()
n = int(input().strip())
w_list = [input().strip() for _ in range(n)]

result = count_anagram_subsequences(s, w_list)
print(result)
