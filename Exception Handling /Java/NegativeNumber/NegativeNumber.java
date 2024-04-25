// Custom exception class

import java.util.Scanner;

class NegativeNumberException extends Exception {
    public NegativeNumberException(String message) {
        super(message);
    }
}

class Solution {
    public int solution(int N) throws NegativeNumberException {
        if (N < 0) {
            throw new NegativeNumberException("NegativeNumberException");
        } else if (N > 0) {
            return 1; // Positive number
        } else {
            return 0; // Zero
        }
    }
}

public class NegativeNumber {
    // Function to determine if number is positive, negative, or zero
    

    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner scn = new Scanner(System.in);
        int input = scn.nextInt();

        try {
            int result = solution.solution(input);
            System.out.println(result);
        } catch (NegativeNumberException e) {
            System.out.println(e.getMessage());
        }
    }
}
