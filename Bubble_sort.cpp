#include<iostream>
using namespace std;


void BubbleSort(int arr[],int n){
    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;

            }
        }
    }
}

int main(){
    int arr[] = {5,4,1,3,2};
    int n = sizeof(arr)/sizeof(int);
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    BubbleSort(arr,n);

    cout<<endl;

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
