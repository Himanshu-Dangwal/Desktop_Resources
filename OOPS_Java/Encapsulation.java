import java.util.Scanner;

class BankAccount {
    private int accountNumber;
    private String accountHolderName;
    private double accountBalance;

    // Constructor to initialize the account
    public BankAccount(int number, String name, double balance) {
        accountNumber = number;
        accountHolderName = name;
        accountBalance = balance;
    }

    // Deposit funds into the account
    public void deposit(double amount) {
        if (amount > 0) {
            accountBalance += amount;
            System.out.println("Deposited " + amount + " into the account.");
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    // Withdraw funds from the account
    public void withdraw(double amount) {
        if (amount > 0 && amount <= accountBalance) {
            accountBalance -= amount;
            System.out.println("Withdrawn " + amount + " from the account.");
        } else {
            System.out.println("Invalid withdrawal amount or insufficient balance.");
        }
    }

    // Get the current account balance
    public String getBalance() {
        return String.format("%.2f",accountBalance);
    }
}

public class Encapsulation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int number = scanner.nextInt();
        String name = scanner.next();
        double balance = scanner.nextDouble();

        // Create a BankAccount object with an initial balance
        BankAccount account = new BankAccount(number, name, balance);

        double depositAmount = scanner.nextDouble();
        // Deposit funds into the account
        account.deposit(depositAmount);

        // Withdraw funds from the account
        double withdrawAmount = scanner.nextDouble();
        account.withdraw(withdrawAmount);

        // Print the current balance of the account
        System.out.println("Current balance: " + account.getBalance());

        scanner.close();
    }
}

