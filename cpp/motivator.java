import java.util.Random;

public class QuoteGenerator {
    public static void main(String[] args) {
        String[] quotes = {
            "Believe in yourself and all that you are.",
            "Do one thing every day that scares you.",
            "Success is not for the lazy.",
            "Your limitation—it’s only your imagination.",
            "Push yourself, because no one else is going to do it for you.",
            "Dream it. Wish it. Do it.",
            "Great things never come from comfort zones.",
            "Don’t stop when you’re tired. Stop when you’re done."
        };

        Random random = new Random();
        int index = random.nextInt(quotes.length);

        System.out.println("✨ Welcome to the Motivational Quote Generator ✨");
        System.out.println("-------------------------------------------------------");
        System.out.println(quotes[index]);
        System.out.println("-------------------------------------------------------");
    }
}
