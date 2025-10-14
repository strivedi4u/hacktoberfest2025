class Solution {
public:
    void backtrack(int n, string &curr, vector<string> &happyStrings) {
        if (curr.size() == n) {
            happyStrings.push_back(curr);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {  // Ensure no two consecutive chars are the same
                curr.push_back(ch);
                backtrack(n, curr, happyStrings);
                curr.pop_back();  // Backtrack
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        string curr = "";
        
        // Generate all happy strings using backtracking
        backtrack(n, curr, happyStrings);

        // If k is greater than the total number of happy strings, return empty string
        if (k > happyStrings.size()) return "";
        
        return happyStrings[k - 1];  // k-th lexicographically sorted string
    }
};
