class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        // dp[i][j] = whether s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true; // empty string matches empty pattern

        // Initialize for patterns like a*, a*b*, etc.
        for (int j = 2; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    // Consider zero occurrence
                    dp[i][j] = dp[i][j - 2];
                    // Consider one or more occurrence
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
