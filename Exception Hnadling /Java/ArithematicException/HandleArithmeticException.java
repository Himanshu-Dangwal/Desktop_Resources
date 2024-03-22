import java.util.Scanner;

public class HandleArithmeticException {

    static void handleArithmeticException(int[] arr) throws ArrayIndexOutOfBoundsException {
        int n = arr.length;

        try {
            for (int i = 0; i <= n; i++) {
                System.out.println(arr[i]);
            }
        } catch (ArrayIndexOutOfBoundsException err) {
            throw err;
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }

        try {
            handleArithmeticException(arr);
        } catch (ArrayIndexOutOfBoundsException err) {
            System.out.print(err.getMessage());
        }
    }
}
