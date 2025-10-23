// MergeSort.java
// Compile: javac MergeSort.java
// Run:     java MergeSort

import java.util.*;

public class MergeSort {

    // Merge two sorted halves of arr[l..m] and arr[m+1..r]
    public static void merge(int[] arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        int[] left = new int[n1];
        int[] right = new int[n2];

        // Copy data to temp arrays
        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        // Merge the two arrays
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        // Copy remaining elements of left[]
        while (i < n1)
            arr[k++] = left[i++];

        // Copy remaining elements of right[]
        while (j < n2)
            arr[k++] = right[j++];
    }

    // Recursive Merge Sort function
    public static void mergeSort(int[] arr, int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        mergeSort(arr, 0, n - 1);

        System.out.println("Sorted array:");
        for (int x : arr)
            System.out.print(x + " ");
        System.out.println();
    }
}
