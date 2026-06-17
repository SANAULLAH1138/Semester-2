#include <iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;
public:
    Account(int accNum, double bal, string holder, string type) {
        accountNumber = accNum;
        balance = bal;
        accountHolderName = holder;
        accountType = type;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        } else {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    virtual void calculateInterest() {}

    virtual void printStatement() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;
public:
    SavingsAccount(int accNum, double bal, string holder, double rate, double minBal)
        : Account(accNum, bal, holder, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Interest added. New balance: " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int accNum, double bal, string holder)
        : Account(accNum, bal, holder, "Checking") {}
};

class FixedDepositAccount : public Account {
    double fixedInterestRate;
    int maturityDate;
public:
    FixedDepositAccount(int accNum, double bal, string holder, double rate, int maturity)
        : Account(accNum, bal, holder, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest() override {
        double interest = balance * fixedInterestRate / 100;
        cout << "Fixed deposit interest: " << interest << endl;
    }
};

int main() {
    SavingsAccount sa(78, 25000, "Sanaullah", 3.5, 1000);
    CheckingAccount ca(122, 25000, "Mehrwan");
    FixedDepositAccount fda(203, 15000, "Vivek", 5.0, 2026);

    sa.printStatement();
    sa.deposit(1000);
    sa.withdraw(2000);
    sa.calculateInterest();
    
    cout << "---------------------" << endl;
    
    ca.printStatement();
    ca.deposit(500);
    ca.withdraw(3000);
    
    cout << "---------------------" << endl;
    
    fda.printStatement();
    fda.calculateInterest();
    
    return 0;
}

