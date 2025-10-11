class Solution {
public:
    int climbStairs(int n) {
      if( n == 1 ) return 1 ;
      int first=1 , second = 2  ;
      for( int i = 3 ; i <= n ; ++i ){
        int third = first + second ;
        first = second ;
        second = third ;
      }
      return second ; 
    
    }
};
