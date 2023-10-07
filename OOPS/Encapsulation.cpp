#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
private:
    // Private member variables
    int accountNumber;
    string accountHolderName;
    double accountBalance;

public:
    // Constructor to initialize the account
    BankAccount(int number, const string &name, double balance)
        : accountNumber(number), accountHolderName(name), accountBalance(balance) {}

    // Public member functions

    // Deposit funds into the account
    void deposit(double amount)
    {
        if (amount > 0)
        {
            accountBalance += amount;
            cout << "Deposited " << amount << " into the account." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw funds from the account
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= accountBalance)
        {
            accountBalance -= amount;
            cout << "Withdrawn " << amount << " from the account." << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient balance." << endl;
        }
    }

    // Get the current account balance
    double getBalance() const
    {
        return accountBalance;
    }
};

int main()
{
    int number;
    double balance;
    string name;

    cin >> number >> name >> balance;
    // Create a BankAccount object with an initial balance of 1000.0
    BankAccount account(number, name, balance);

    double depositAmount;
    cin >> depositAmount;
    // Deposit 500.0 into the account
    account.deposit(depositAmount);

    // Withdraw 200.0 from the account
    double withdrawAmount;
    cin >> withdrawAmount;
    account.withdraw(withdrawAmount);

    // Print the current balance of the account
    cout << "Current balance: " << account.getBalance() << endl;

    return 0;
}
