import java.util.Scanner;
import java.util.Stack;

public class stackQuestion {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();

        // Insertion : Push
        for (int i = 0; i < 5; i++) {
            int value = scn.nextInt();
            stack.push(value);
        }

        // Size
        System.out.println(stack.size());

        // Peek
        if (!stack.isEmpty()) {
            System.out.println(stack.peek());
        }

        // Pop
        if (!stack.isEmpty()) {
            int popped = stack.pop();
            System.out.println(popped);
        }

        // Clear
        stack.clear();

        // isEmpty()
        if (stack.isEmpty()) {
            System.out.println("Stack is empty");
        }
    }
}
