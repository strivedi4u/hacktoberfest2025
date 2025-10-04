class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int ans=0;
        vector<pair<int,int>> vp;
        for(int i=0; i<height.size(); i++)
        {
            vp.push_back({height[i], i});
        }
        sort(vp.begin(), vp.end());
        set<int> st;
        for(int i=0; i<n; i++) st.insert(i);
        for(int i=0; i<n; i++)
        {
            int a = vp[i].first;
            int b = vp[i].second;

            int maxi=*(st.begin());
            auto it=st.end();
            it--;
            int mini=*(it);
            // cout<<maxi<<" "<<mini<<endl;
            int x = abs((maxi-b))*a;
            int y = abs((b-mini))*a;
            ans=max(ans, max(x,y));
            // cout<<x<<" "<<y<<endl;
            st.erase(b);
        }
        return ans;
    }
};
