class Solution {
private:
    vector<int> findNextSmallest(vector<int> heights, int n){
        stack<int> S;
        vector<int> arr(n);

        S.push(-1); // push -1 for no answer

        for(int i=n-1; i>=0; i--){
            int el = heights[i];
            while(S.top() != -1 && heights[S.top()] >= el){
                S.pop();
            }
            arr[i] = S.top();
            S.push(i);  // we have to push its index
        }
        return arr;
    }

    vector<int> findPrevSmallest(vector<int> heights, int n){
        stack<int> S;
        vector<int> arr(n);

        S.push(-1); // push -1 for no answer

        for(int i=0; i<n; i++){
            int el = heights[i];
            while(S.top() != -1 && heights[S.top()] >= el){
                S.pop();
            }
            arr[i] = S.top();
            S.push(i);  // we have to push its index
        }
        return arr;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = findNextSmallest(heights,n);

        vector<int>prev(n);
        prev = findPrevSmallest(heights,n);

        int Area = INT_MIN;

        for(int i=0; i<n; i++){
            int length = heights[i];
            
            // Edge Case    // when same els all    -1+1-1 = -1 Area cant be -ve
            if(next[i] == -1){
                next[i] = n;
            }

            int width = next[i] - prev[i] - 1;

            int rectArea = length * width;
            Area = max(Area,rectArea);
        }
        return Area;
    }
};
