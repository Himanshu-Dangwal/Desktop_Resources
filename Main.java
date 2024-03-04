import java.util.Scanner;
class Adder {
    
    // 1. Adding two integers
    public static int add(int a, int b) {
        return a + b;
    }

    // 2. Adding two doubles
    public static double add(double a, double b) {
        return a + b;
    }

    // 3. Adding three integers
    public static int add(int a, int b, int c) {
        return a + b + c;
    }

    // 4. Adding three doubles
    public static double add(double a, double b, double c) {
        return a + b + c;
    }

    // 5. Adding an array of integers
    public static int add(int[] numbers) {
        int sum = 0;
        for (int num : numbers) {
            sum += num;
        }
        return sum;
    }

    // 6. Adding an array of doubles
    public static double add(double[] numbers) {
        double sum = 0;
        for (double num : numbers) {
            sum += num;
        }
        return sum;
    }

    
   
}


public class Main {
    public static void main(String[] args) {
        // Testing different overloaded add methods
        Scanner scn = new Scanner(System.in);
        int a = scn.nextInt();
        // Scenario 1
        System.out.println("1. Adding two integers: " + Adder.add(a, 10));

        // Scenario 2
        System.out.println("2. Adding two doubles: " + Adder.add(3.5, 2.5));

        // Scenario 3
        System.out.println("3. Adding three integers: " + Adder.add(a, 8, 9));

        // Scenario 4
        System.out.println("4. Adding three doubles: " + Adder.add(1.5, 2.5, 3.5));

        // Scenario 5
        int[] intArray = {a, 2, 3, 4, 5};
        System.out.println("5. Adding an array of integers: " + Adder.add(intArray));

        // Scenario 6
        double[] doubleArray = {2.5, 3.5, 4.5};
        System.out.println("6. Adding an array of doubles: " + Adder.add(doubleArray));

       
    }
}
