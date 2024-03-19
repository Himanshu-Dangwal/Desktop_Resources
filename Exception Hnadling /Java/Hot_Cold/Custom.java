import java.util.Scanner;

class TooColdException extends Exception {
    public TooColdException(String message) {
        super(message);
    }
}

class TooHotException extends Exception {
    public TooHotException(String message) {
        super(message);
    }
}

class Customer {
    int giveCupOfCoffee(int temperature) throws TooColdException, TooHotException {
        if (temperature < 35) {
            throw new TooColdException("Coffee is too cold!");
        } else if (temperature > 60) {
            throw new TooHotException("Coffee is too hot!");
        } else {
            return 1; // Coffee is at a perfect temperature
        }
    }
}

public class Custom {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int temperature = scn.nextInt();
        Customer customer = new Customer(); // Instantiate Customer class

        try {
            System.out.println(customer.giveCupOfCoffee(temperature));
        } catch (TooColdException e) {
            System.out.println(e.getMessage());
        } catch (TooHotException e) {
            System.out.println(e.getMessage());
        }
    }
}
