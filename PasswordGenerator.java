import java.util.*;

public class PasswordGenerator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("===== Random Password Generator =====");

        System.out.print("Enter desired password length: ");
        int length = sc.nextInt();

        System.out.println("Choose password difficulty:");
        System.out.println("1. Easy (only letters)");
        System.out.println("2. Medium (letters + numbers)");
        System.out.println("3. Hard (letters + numbers + symbols)");
        System.out.print("Enter your choice (1/2/3): ");
        int choice = sc.nextInt();

        String password = generatePassword(length, choice);
        System.out.println("\nYour Random Password is: " + password);

        System.out.println("\n=== Password Strength ===");
        if (length < 6) {
            System.out.println("Weak ⚠️");
        } else if (length <= 10) {
            System.out.println("Strong 💪");
        } else {
            System.out.println("Very Strong 🔥");
        }

        sc.close();
    }

    public static String generatePassword(int length, int choice) {
        String letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String numbers = "0123456789";
        String symbols = "!@#$%^&*()-_=+<>?";

        String characters = "";

        switch (choice) {
            case 1:
                characters = letters;
                break;
            case 2:
                characters = letters + numbers;
                break;
            case 3:
                characters = letters + numbers + symbols;
                break;
            default:
                System.out.println("Invalid choice! Using default (Medium).");
                characters = letters + numbers;
        }

        Random rand = new Random();
        StringBuilder password = new StringBuilder();

        for (int i = 0; i < length; i++) {
            password.append(characters.charAt(rand.nextInt(characters.length())));
        }

        return password.toString();
    }
}
