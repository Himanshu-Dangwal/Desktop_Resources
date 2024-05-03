import java.util.HashSet;
import java.util.Scanner;

public class HashSetQuestion {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        HashSet<Integer> set = new HashSet<>();

        // Insertion
        for (int i = 0; i < 5; i++) {
            int value = scn.nextInt();
            set.add(value);
        }

        // Size
        System.out.println(set.size());

        // Check if HashSet contains value: 3
        int x = scn.nextInt();
        if (set.contains(x)) {
            System.out.println("Yes");
        }

        // Iterate
        for (Integer number : set) {
            System.out.println(number);
        }

        // Add Duplicate
        int duplicate = scn.nextInt();
        boolean added = set.add(duplicate);
        System.out.println(added ? "Successful" : "Not successful");

        // Remove
        int removeValue = scn.nextInt();
        if (set.remove(removeValue)) {
            System.out.println("Removed " + removeValue);
        } else {
            System.out.println("Value not found, nothing removed");
        }

        // Clear
        set.clear();

        // isEmpty()
        if (set.isEmpty()) {
            System.out.println("HashSet is empty");
        }
    }
}
