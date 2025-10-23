class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0 ;
        for ( int i = 0 ; i < n ; i++){
            sum += nums[i];
        }
        int  s = 0 ;
        int e  = sum ;
        int ans = -1 ;
        int mid = s+ (e-s)/2 ;
        while( s<= e){
            if (isPossibleans ( nums, k , n , mid) ){
                ans = mid ;
                e = mid-1 ;
            }
            else{
                s = mid + 1; 
            }
            mid = s + (( e-s )/2);
        }
        return ans;
    }
private:
    bool isPossibleans(vector<int>& nums, int k , int n ,  int mid ){
        int division = 1 ;
        int sumnumber = 0 ;

        for( int i = 0 ; i < n ; i++){
            if(sumnumber + nums[i] <= mid ){
                sumnumber += nums[i];
            }
            else{
                division++ ;
                if( division > k || nums[i] > mid){
                    return false ;
                }
                sumnumber = nums[i]; 
            }
        }
        return true ;
    }
};
