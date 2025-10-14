class BubbleSort{

    static void BubbleSort(int arr[]){
        int n = arr.length;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    cnt++;
                }
            }
            if(cnt==0){
                break;
            }
        }
    }
}
