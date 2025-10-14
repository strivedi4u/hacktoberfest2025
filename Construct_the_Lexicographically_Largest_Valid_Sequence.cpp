class Solution {
private:
    bool backtrack(vector<int>& sequence, vector<bool>& used, int pos, int n, int size) {
        // If we've filled all positions, we've found a valid sequence
        if (pos >= size) {
            return true;
        }
        
        // Skip if position is already filled
        if (sequence[pos] != 0) {
            return backtrack(sequence, used, pos + 1, n, size);
        }
        
        // Try placing numbers from highest to lowest for lexicographically largest
        for (int num = n; num >= 1; num--) {
            // Skip if number is already used
            if (used[num]) continue;
            
            // For numbers >= 2, check if we can place the second occurrence
            if (num >= 2) {
                // Check if second position is within bounds and empty
                if (pos + num >= size || sequence[pos + num] != 0) continue;
                
                // Place both occurrences
                sequence[pos] = num;
                sequence[pos + num] = num;
                used[num] = true;
                
                if (backtrack(sequence, used, pos + 1, n, size)) {
                    return true;
                }
                
                // Backtrack
                sequence[pos] = 0;
                sequence[pos + num] = 0;
                used[num] = false;
            }
            // For number 1, just place it once
            else {
                sequence[pos] = num;
                used[num] = true;
                
                if (backtrack(sequence, used, pos + 1, n, size)) {
                    return true;
                }
                
                // Backtrack
                sequence[pos] = 0;
                used[num] = false;
            }
        }
        
        return false;
    }
    
public:
    vector<int> constructDistancedSequence(int n) {
        // Calculate size: 2*(n-1) + 1
        // n-1 numbers appear twice, 1 appears once
        int size = 2 * (n - 1) + 1;
        
        // Initialize sequence with zeros
        vector<int> sequence(size, 0);
        
        // Track used numbers
        vector<bool> used(n + 1, false);
        
        // Start backtracking from position 0
        backtrack(sequence, used, 0, n, size);
        
        return sequence;
    }
};
