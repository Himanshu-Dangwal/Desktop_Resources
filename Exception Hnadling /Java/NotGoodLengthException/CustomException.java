// Custom exception class

import java.util.Scanner;

class NotGoodLengthException extends Exception {
    public NotGoodLengthException(String message) {
        super(message);
    }
}

class Solution{
    public int solution(String S) throws NotGoodLengthException {
        int length = S.length();
        if (length < 10) {
            throw new NotGoodLengthException("NotGoodLengthException");
        } else {
            return length;
        }
    }
}

public class CustomException {
    // Function to find the length of string or throw NotGoodLengthException
    

    public static void main(String[] args) {
        Solution solution = new Solution();
        Scanner scn = new Scanner(System.in);

        String input = scn.next();

        try {
            int result = solution.solution(input);
            System.out.println(result);
        } catch (NotGoodLengthException e) {
            System.out.println(e.getMessage());
        }
    }
}
