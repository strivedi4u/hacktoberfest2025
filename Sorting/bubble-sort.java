// Bubble Sort in Java
public class BubbleSortExample {
    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 4, 2};  // Unsorted array
        bubbleSort(arr);

        System.out.println("Sorted array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }
    }

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        boolean swapped;

        // Traverse through all elements
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            // Last i elements are already sorted
            for (int j = 0; j < n - i - 1; j++) {
                // Swap if element is greater than the next one
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                }
            }

            // If no two elements were swapped, array is sorted
            if (!swapped)
                break;
        }
    }
}
