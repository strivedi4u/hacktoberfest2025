class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta; 
        int sn = s.length();
        sta.push(-1);
        int maxl =0 ;
        for( int i = 0 ; i< sn ; i++){
            if( s[i] =='('){
                sta.push(i);
            }
            else{
                sta.pop();
                if( sta.empty() ){
                    sta.push(i);
                }
                else{
                    int len = i - sta.top();
                    maxl = max(len , maxl);
                }
            }
        }
        return maxl ;
    }
};
