import java.util.*;
abstract class AbstractBankAccount {
    protected double balance;

    public AbstractBankAccount(double initialBalance) {
        this.balance = initialBalance;
    }

    // Abstract methods
    public abstract void deposit(double amount);

    public abstract void withdraw(double amount);

    public abstract double getBalance();
}

class SavingsAccount extends AbstractBankAccount {

    // Constructor to initialize the balance
    public SavingsAccount(double initialBalance) {
        super(initialBalance);
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

public class Abstract_BankAccount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        double amount = scanner.nextDouble();
        SavingsAccount account = new SavingsAccount(amount);

        System.out.println("Initial balance: " + account.getBalance());

        double depositAmount = scanner.nextDouble();
        account.deposit(depositAmount);

        double withdrawAmount = scanner.nextDouble();
        account.withdraw(withdrawAmount);

        System.out.println("Updated balance: " + account.getBalance());

        scanner.close();
    }
}