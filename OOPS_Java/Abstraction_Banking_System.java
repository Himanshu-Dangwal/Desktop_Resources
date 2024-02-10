import java.util.Scanner;

class BankAccount {
    private double balance;

    // Constructor to initialize the balance
    public BankAccount(double initialBalance) {
        balance = initialBalance;
    }

    // Deposit method
    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Depositing " + amount + "...");
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    // Withdraw method
    public void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            System.out.println("Withdrawal of " + amount + "...");
        } else {
            System.out.println("Insufficient funds or invalid withdrawal amount.");
        }
    }

    // Get balance method
    public double getBalance() {
        return balance;
    }
}

public class Abstraction_Banking_System {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double amount = scanner.nextDouble();
        BankAccount account = new BankAccount(amount);

        System.out.println("Initial balance: " + account.getBalance());

        double depositAmount = scanner.nextDouble();
        account.deposit(depositAmount);

        double withdrawAmount = scanner.nextDouble();
        account.withdraw(withdrawAmount);

        System.out.println("Updated balance: " + account.getBalance());

        scanner.close();
    }
}

