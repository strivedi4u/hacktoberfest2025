class Solution {
public:
    vector<int>ans;
    void f(vector<vector<int>>& matrix, int fr, int lr, int fc, int lc){
        for(int i=fc;i<=lc;i++){
            ans.push_back(matrix[fr][i]);
        }
        for(int i=fr+1;i<=lr;i++){
            ans.push_back(matrix[i][lc]);
        }
        if(fr<lr){
            for(int i=lc-1;i>=fc;i--){
                ans.push_back(matrix[lr][i]);
            }
        }
        if(fc<lc){
            for(int i=lr-1;i>=(fr+1);i--){
                ans.push_back(matrix[i][fc]);
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int fr=0;
        int lr=matrix.size()-1;
        int fc=0;
        int lc=matrix[0].size()-1;
        while(fr<=lr && fc<=lc){
            f(matrix,fr,lr,fc,lc);
            fr++;
            fc++;
            lr--;
            lc--;
        }
        return ans;
    }
};
