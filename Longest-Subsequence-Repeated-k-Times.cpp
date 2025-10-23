//bfs is new concept i have watched a video to solve it 
class Solution {
    int countSubsequences(const string& s,const string& next){
        int i=0;
        int j=0;
        int m = next.size();
        int subsequence_count = 0;

        while(i<s.size()){
            if(s[i]==next[j]){
                j++;
                if(j==m){
                    j=0;
                    subsequence_count++;
                }
            }
            i++;
        }
        return subsequence_count;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        vector<int> freq(26);
        for(int i=0;i<n;++i)
            freq[s[i]-'a']++;
        string curr = "";
        queue<string> q;
        q.push(curr);
        string res;

        while(!q.empty()){
            curr = q.front();
            q.pop();
            
            string next = curr;
            for(char c='a';c<='z';++c){
                if(freq[c-'a']<k)
                    continue;
                next.push_back(c);
                if(countSubsequences(s,next)>=k){
                    res = next;
                    q.push(next);
                }
                next.pop_back();
            }
        }
        return res;
    }
};
