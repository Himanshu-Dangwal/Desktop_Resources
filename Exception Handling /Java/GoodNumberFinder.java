import java.util.Scanner;

public class GoodNumberFinder {

    static String findGoodNumber(int n, int low, int high) throws Exception {
        int cnt = 0;
        for (int i = 2; i * i <= n; i++) {
            boolean flag = false;
            while (n % i == 0) {
                flag = true;
                n /= i;
            }

            if (flag) {
                cnt++;
            }
        }

        if (n != 1) {
            cnt++;
        }

        if (cnt < low) {
            throw new Exception("Count is less");
        }
        if (cnt > high) {
            throw new Exception("Count is high");
        }

        return "Count is perfect";
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int low = scanner.nextInt();
        int high = scanner.nextInt();

        try {
            System.out.println(findGoodNumber(n, low, high));
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}
