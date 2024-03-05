import java.util.Scanner;

// Interface representing a payment method
interface PaymentMethod {
    void processPayment(double amount);
    String getPaymentDetails();
}

// CreditCardPayment class implementing PaymentMethod interface
class CreditCardPayment implements PaymentMethod {
    private long cardNumber;
    private String expiryDate;

    // Parameterized constructor
    public CreditCardPayment(long cardNumber, String expiryDate) {
        this.cardNumber = cardNumber;
        this.expiryDate = expiryDate;
    }

    // Method to process credit card payment
    @Override
    public void processPayment(double amount) {
        System.out.println("Credit Card Transaction Authorized.");
    }

    // Method to get credit card payment details
    @Override
    public String getPaymentDetails() {
        return String.format("Card Number: %d\nExpiry Date: %s", cardNumber, expiryDate);
    }

}

// PayPalPayment class implementing PaymentMethod interface
class PayPalPayment implements PaymentMethod {
    private String email;

    // Parameterized constructor
    public PayPalPayment(String email) {
        this.email = email;
    }

    // Method to process PayPal payment
    @Override
    public void processPayment(double amount) {
        System.out.println("PayPal Transaction Processed.");
    }

    // Method to get PayPal payment details
    @Override
    public String getPaymentDetails() {
        return String.format("Email: %s", email);
    }

}

// OnlineShop class
class OnlineShop {
    private PaymentMethod paymentMethod;

    // Parameterized constructor
    public OnlineShop(PaymentMethod paymentMethod) {
        this.paymentMethod = paymentMethod;
    }

    // Method to process an order with the given total amount using the specified payment method
    public void processOrder(double totalAmount) {
        paymentMethod.processPayment(totalAmount);
    }

    // Method to display payment details after processing the order
    public void displayPaymentDetails() {
        System.out.println("Payment Details:");
        System.out.println(paymentMethod.getPaymentDetails());
    }
}

// Main class
public class Payment_methods {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read payment method type
        int paymentMethodType = scanner.nextInt();
        PaymentMethod paymentMethod;

        if (paymentMethodType == 1) {
            // Credit Card payment
            long cardNumber = scanner.nextLong();
            String expiryDate = scanner.next();
            paymentMethod = new CreditCardPayment(cardNumber, expiryDate);
        } else if (paymentMethodType == 2) {
            // PayPal payment
            String email = scanner.next();
            paymentMethod = new PayPalPayment(email);
        } else {
            // Handle invalid payment method type
            System.out.println("Invalid Payment Method Type");
            return;
        }



        // Read total order amount
        double totalAmount = scanner.nextDouble();

        // Create OnlineShop instance and process the order
        OnlineShop onlineShop = new OnlineShop(paymentMethod);
        onlineShop.processOrder(totalAmount);

        // Display payment details after processing the order
        onlineShop.displayPaymentDetails();

        scanner.close();
    }
}
