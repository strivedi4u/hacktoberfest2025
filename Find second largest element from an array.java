import java.util.List;

public class SecondLargest {

    public static int getSecondLargest(List<Integer> arr) {
        int n = arr.size();

      
        int largest = -1;
        int secondLargest = -1;

        
        for (int i = 0; i < n; i++) {
            if (arr.get(i) > largest) {
                secondLargest = largest;
                largest = arr.get(i);
            } else if (arr.get(i) < largest && arr.get(i) > secondLargest) {
                secondLargest = arr.get(i);
            }
        }
        return secondLargest;
    }

    public static void main(String[] args) {
        List<Integer> arr = List.of(12, 35, 1, 10, 34, 1);
        System.out.println("Second Largest: " + getSecondLargest(arr));
    }
}
