import java.util.*;

public class insertionSort {
    public static void main(String[] args) {
        int[] arr = {5, 3, 8, 4, 2};
        for (int i = 1; i < arr.length - 1; i++) {
        int current = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = current;
    }
