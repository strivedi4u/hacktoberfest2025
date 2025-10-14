import java.util.Scanner;

public class Palindrome {
    public static void checkPalindrome(String str) {
        int start = 0;
        int end = str.length() - 1;
        
        while (start < end) {
            if (str.charAt(start) != str.charAt(end)) {
                System.out.println("The string is not a palindrome.");
                return;
            }
            start++;
            end--;
        }
        
        System.out.println("The string is a palindrome.");
    }

    public static void main(String[] args) {
        Scanner in = new Scanner (System.in);
        System.out.print("Enter a string: ");
         String input = in.nextLine();
        checkPalindrome(input);
    }
}
