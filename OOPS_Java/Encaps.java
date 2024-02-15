import java.util.Scanner;

class BankAccount {
    private int accountNumber;
    private String accountHolderName;
    private double accountBalance;

    // Constructor to initialize the account
    public BankAccount(int number, String name, double balance) {
        this.accountNumber = number;
        this.accountHolderName = name;
        this.accountBalance = balance;
    }

    // Getter methods
    public int getAccountNumber() {
        return accountNumber;
    }

    public String getAccountHolderName() {
        return accountHolderName;
    }

    public double getAccountBalance() {
        return accountBalance;
    }

    // Setter methods
    public void setAccountHolderName(String name) {
        this.accountHolderName = name;
    }

    public void setAccountBalance(double balance) {
        this.accountBalance = balance;
    }
}

public class Encaps {
    public static void main(String[] args) {
        // Create a BankAccount object with an initial balance
        BankAccount account = new BankAccount(12345, "John Doe", 1000.0);

        Scanner scn = new Scanner(System.in);
        double updatedBalance = scn.nextDouble();
        // Display initial account information
        System.out.println("Initial Account Information:");
        displayAccountInfo(account);

        // Update account details using setter methods

        account.setAccountHolderName("Jane Doe");
        account.setAccountBalance(updatedBalance);

        // Display updated account information
        System.out.println("\nUpdated Account Information:");
        displayAccountInfo(account);
    }

    // Helper method to display account information
    private static void displayAccountInfo(BankAccount account) {
        System.out.println("Account Number: " + account.getAccountNumber());
        System.out.println("Account Holder Name: " + account.getAccountHolderName());
        System.out.println("Account Balance: $" + account.getAccountBalance());
        System.out.println();
    }
}
