/*
 Beaturiful Xor : You are given two integers a and b. You are allowed to perform the following operation any number of times (including zero):
choose any integer x such that 0≤x≤a  (the current value of a, not initial),set a:=a⊕x. Here, ⊕ represents the bitwise XOR operator.
After performing a sequence of operations, you want the value of a to become exactly b.

Find a sequence of at most 100 operations (values of x used in each operation) that transforms a into b, or report that it is impossible.

Note that you are not required to find the minimum number of operations, but any valid sequence of at most 100  operations.
*/
#include <bits/stdc++.h>
#define lil long long int
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int test;cin>>test;
	while(test--)
	{
	    lil a,b;cin>>a>>b;
        if(a==b){
            cout<<"0\n";
            continue;   
        }
        vector<int>ans;
        int flag=0;
        for(int i=0;i<32;i++)
        {
            int bita= (1<<i)&a;
            int bitb= (1<<i)&b;
            if(bita!=bitb){
                if((1<<i)>a){
                    flag=1;
                    break;
                }
                ans.push_back((1<<i));
                a=a^((1<<i));
            }
        }
        if(flag==1){
            cout<<"-1\n";
            continue;
        }
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        
        cout<<"\n";
	}

}
