
import java.util.*;

public class SecondLargestElement{
    public static int findSecondLargest(String input) {
        String[] numbers = input.split(" ");

        if (numbers.length < 2) {
            // If there are less than two elements, there is no second largest
            return -1;
        }

        int first = Integer.MIN_VALUE;
        int second = Integer.MIN_VALUE;

        for (String number : numbers) {
            int current = Integer.parseInt(number);

            if (current > first) {
                // If the current number is greater than the largest, update both first and second
                second = first;
                first = current;
            } else if (current > second && current < first) {
                // If the current number is greater than the second largest but less than the largest, update second
                second = current;
            }
        }

        if (second == Integer.MIN_VALUE) {
            // If second remains as its initial value, there is no second largest
            return -1;
        }

        return second;
    }

    public static void main(String[] args) {
        // Example Usage:
        Scanner scn = new Scanner(System.in);
        String inputLine = scn.nextLine();
        
        int result = findSecondLargest(inputLine);
        System.out.println(result);
    }
    
}
