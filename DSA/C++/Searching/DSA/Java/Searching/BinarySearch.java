import java.util.Scanner;

public class BinarySearch {

    // Binary search function
    public static int binarySearch(int[] arr, int x) {
        int low = 0, high = arr.length - 1;
        while (low <= high) {
            // Avoid potential overflow: use mid = low + (high - low) / 2
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) return mid;   // Element found
            else if (arr[mid] < x) low = mid + 1;  // Search right half
            else high = mid - 1;                     // Search left half
        }
        return -1; // Element not found
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter elements in sorted order:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter element to search: ");
        int x = sc.nextInt();

        int result = binarySearch(arr, x);

        if (result != -1) {
            System.out.println("Element found at index: " + result);
        } else {
            System.out.println("Element not found.");
        }

        sc.close();
    }
}
