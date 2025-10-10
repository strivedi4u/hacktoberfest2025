import java.util.Scanner;

public class BinarySearch {

    // Binary search method
    public static int binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;  // Find the middle element

            // Check if target is present at mid
            if (array[mid] == target) {
                return mid;
            }
            // If target is greater, ignore left half
            if (array[mid] < target) {
                left = mid + 1;
            }
            // If target is smaller, ignore right half
            else {
                right = mid - 1;
            }
        }
        // Target not found
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking input for the array size
        System.out.print("Enter the number of elements in the array: ");
        int size = scanner.nextInt();

        int[] array = new int[size];

        // Taking input for array elements (assuming sorted array)
        System.out.println("Enter " + size + " sorted integers: ");
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        // Taking input for the target element
        System.out.print("Enter the target element to search: ");
        int target = scanner.nextInt();

        // Perform binary search
        int result = binarySearch(array, target);

        // Output the result
        if (result == -1) {
            System.out.println("Element not present in the array.");
        } else {
            System.out.println("Element found at index " + result);
        }

        scanner.close();
    }
}
