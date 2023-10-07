#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    double balance;

public:
    // Constructor to initialize the balance
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Deposit method
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Depositing " << amount << "..." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw method
    void withdraw(double amount)
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            cout << "Withdrawal of " << amount << "..." << endl;
        }
        else
        {
            cout << "Insufficient funds or invalid withdrawal amount." << endl;
        }
    }

    // Get balance method
    double getBalance()
    {
        return balance;
    }
};

int main()
{
    double amount;
    cin >> amount;
    BankAccount account(amount);

    cout << "Initial balance: " << account.getBalance() << endl;

    double depositAmount;
    cin >> depositAmount;
    account.deposit(depositAmount);

    double withdrawAmount;
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    cout << "Updated balance: " << account.getBalance() << endl;

    return 0;
}
