import java.util.HashMap;

public class HashMapExample {

    public static void main(String[] args) {
        // Creating a HashMap to store Integer keys and String values
        HashMap<Integer, String> map = new HashMap<>();

        // Adding key-value pairs to the HashMap
        map.put(1, "Apple");
        map.put(2, "Banana");
        map.put(3, "Mango");
        map.put(4, "Grapes");
        
        // Displaying the HashMap
        System.out.println("HashMap: " + map);
        
        // Accessing a value by its key
        String value = map.get(2); // Key 2 -> "Banana"
        System.out.println("Value for key 2: " + value);
        
        // Removing an entry from the HashMap
        map.remove(3); // Removes the key 3 (Mango)
        System.out.println("After removing key 3: " + map);
        
        // Checking if a key exists
        boolean containsKey = map.containsKey(1);
        System.out.println("Does key 1 exist? " + containsKey);
        
        // Checking if a value exists
        boolean containsValue = map.containsValue("Apple");
        System.out.println("Does value 'Apple' exist? " + containsValue);
        
        // Iterating over the keys and values
        System.out.println("Iterating over keys and values:");
        for (HashMap.Entry<Integer, String> entry : map.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }
    }
}
