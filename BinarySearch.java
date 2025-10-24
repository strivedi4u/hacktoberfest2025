public class binarysearch {

    public static void search(int arr[],int low, int high, int targ){
        if (low==high) {
            if(targ==arr[low]){
                System.out.println("element found at index"+low);
            }
            else{
                System.out.println("element not found");
            }
            return;
        }
        int mid = (low+high)/2;
        if (arr[mid]==targ) {
           System.out.println("Element found at index"+ mid); 
        }
        else if(arr[mid]<targ){
            low = mid+1;
            search(arr, low, high, targ);
            
        }
        else if(arr[mid]>targ){
            high = mid-1;
            search(arr, low, high, targ);
        }
        else{
            System.out.println("Element not found");
        }
    }
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,10,22};
        search(arr, 0, arr.length-1,22);
    }
}
