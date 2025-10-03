#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> possibleWords(vector<int> &arr) {
        vector<string> mapping = {
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        if (arr.empty()) return {};

        // start with an empty prefix
        vector<string> res{""};

        for (int d : arr) {
            if (d < 0 || d > 9) continue;            // ignore invalid digits (optional)
            const string &letters = mapping[d];
            if (letters.empty()) {
                // skip digits 0 and 1 (no mapping) instead of returning empty
                continue;
            }

            vector<string> next;
            next.reserve(res.size() * letters.size());
            for (const string &pref : res) {
                for (char ch : letters) {
                    next.push_back(pref + ch);
                }
            }
            res.swap(next);
        }

        // If all digits were skipped (e.g., arr had only 0s and 1s), return empty list
        if (res.size() == 1 && res[0].empty()) return {};

        return res;
    }
};
