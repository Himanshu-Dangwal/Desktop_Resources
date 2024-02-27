import java.util.Scanner;

interface Product {
    void displayDetails();
    double calculatePrice(int quantity);
}

interface Taxable {
    double calculateTax(double price);
}

class GroceryItem implements Product, Taxable {
    private String productName;
    private double unitPrice;
    private int quantityInStock;

    public GroceryItem(String productName, double unitPrice, int quantityInStock) {
        this.productName = productName;
        this.unitPrice = unitPrice;
        this.quantityInStock = quantityInStock;
    }

    @Override
    public void displayDetails() {
        System.out.println("Product Details:");
        System.out.println("Name: " + productName);
        System.out.println("Unit Price: $" + unitPrice);
        System.out.println("Quantity in Stock: " + quantityInStock);
    }

    @Override
    public double calculatePrice(int quantity) {
        double totalPrice = unitPrice * quantity;
        System.out.println("\nTotal Price for " + quantity + " units: $" + totalPrice);
        return totalPrice;
    }

    @Override
    public double calculateTax(double price) {
        double taxRate = 0.07; // 7% tax rate
        double taxAmount = price * taxRate;
        System.out.println("Tax Amount: $" + taxAmount);
        return taxAmount;
    }
}

public class Interface2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for GroceryItem
        String productName = scanner.nextLine();
        double unitPrice = scanner.nextDouble();
        int quantityInStock = scanner.nextInt();

        GroceryItem groceryItem = new GroceryItem(productName, unitPrice, quantityInStock);
        groceryItem.displayDetails();

        // Input for quantity to purchase
        int quantityToPurchase = scanner.nextInt();

        // Calculate and display total price and tax amount
        double totalPrice = groceryItem.calculatePrice(quantityToPurchase);
        groceryItem.calculateTax(totalPrice);
    }
}
