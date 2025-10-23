// given num is armstrong num or not

#include<iostream>
#include<math.h>
using namespace std;

int f(int n,int d){
    if(n==0) return 0;
     return (pow(n%10,d)+f(n/10,d));
   
}
int main(){
    int n,d;
    cout<<"Enter the num to check"<<endl;
    cin>>n;
    int no_of_digits=0;
    int temp=n;
    while(temp>0){
        temp/=10;
        no_of_digits++;
    }
    d=no_of_digits;
    int result=f(n,d);
    if(n==result){
        cout<<"yes"<<endl;

    }
    else{
        cout<<"no"<<endl;
    }
return 0;
}
