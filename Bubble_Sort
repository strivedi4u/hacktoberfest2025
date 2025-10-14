import java.util.Scanner;

public class BubbleSort {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        //input for size
        System.out.print("Enter the number of elements: ");
        int size = scanner.nextInt();
        int[] nums = new int[size];
        
        System.out.println("Enter the elements of the array:");
        for (int i = 0; i < size; i++) {
            nums[i] = scanner.nextInt();
        }

        int temp;

        System.out.println("Before sorting:");
        for (int num : nums) {
            System.out.println(num);
        }

        // Bubble sort logic
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp; 
                }
            }
        }

        //Output
        System.out.println("After sorting:");
        for (int num : nums) {
            System.out.println(num);
        }

        scanner.close();
    }
}
