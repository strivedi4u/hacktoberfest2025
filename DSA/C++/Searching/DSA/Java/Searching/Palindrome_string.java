public class Palindrome_string {
    public static boolean isPalindrome(String str) {
       
        str = str.replaceAll("\\s+", "").toLowerCase();

        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str.charAt(left) != str.charAt(right)) {
                return false; 
            }
            left++;
            right--;
        }
        return true; 
    }

    public static void main(String[] args) {
        String input = "madam";
        System.out.println(isPalindrome(input));
    }
}
