package java;

import java.util.HashSet;

public class DuplicateChecker {
    public static boolean containsDuplicate(int[] nums) {
        HashSet<Integer> seen = new HashSet<>();

        for (int num : nums) {
            // If we have already seen the number, return true
            if (!seen.add(num)) {
                return true;
            }
        }
        // No duplicates found
        return false;
    }

    public static void main(String[] args) {
        int[] numbers = {1, 2, 3, 4, 5, 1};

        boolean hasDuplicate = containsDuplicate(numbers);

        if (hasDuplicate) {
            System.out.println("Array contains duplicates.");
        } else {
            System.out.println("All elements are distinct.");
        }
    }
}
