import java.util.ArrayList;
import java.util.Scanner;

public class arrayListQuestion {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<>();

        // Insertion
        for (int i = 0; i < 5; i++) {
            int value = scn.nextInt();
            numbers.add(value);
        }

        // Size
        System.out.println("Size of ArrayList is " + numbers.size());

        // Check if ArrayList contains value: 3
        if (numbers.contains(3)) {
            System.out.println("Value 3 is present");
        }

        // Iterate
        for (Integer number : numbers) {
            System.out.println(number);
        }

        // IndexOf
        int index = numbers.indexOf(3);
        if (index != -1) {
            System.out.println("Index of value 3: " + index);
        } else {
            System.out.println("Value 3 not found in ArrayList");
        }

        // Remove
        int removeIndex = scn.nextInt();
        if (removeIndex >= 0 && removeIndex < numbers.size()) {
            numbers.remove(removeIndex);
        }

        // Print size and ArrayList after remove
        System.out.println("Size of ArrayList after remove: " + numbers.size());
        for (Integer number : numbers) {
            System.out.println(number);
        }

        // Clear
        numbers.clear();

        // isEmpty()
        if (numbers.isEmpty()) {
            System.out.println("ArrayList is empty");
        }
    }
}
