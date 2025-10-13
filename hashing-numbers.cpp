#include<stdio.h>
using namespace std
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int hash[n];
  for(int i=0;i<n;i++){
    hash[arr[i]]+=1;
  }
  int q;  //number of input values
  cin>>q;
  while(q--){
    int number;
    cin>>number;
    cout<<hash[number]<<endl;
  }
  return 0;
}

  
