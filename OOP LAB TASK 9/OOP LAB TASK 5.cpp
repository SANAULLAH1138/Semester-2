#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawalLimit;
    double depositedToday;
    double withdrawnToday;

public:
    Wallet() : balance(0), dailyDepositLimit(10000), dailyWithdrawalLimit(5000), depositedToday(0), withdrawnToday(0) {}

    bool deposit(double amount) {
        if (amount <= 0 || depositedToday + amount > dailyDepositLimit) return false;
        balance += amount;
        depositedToday += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || withdrawnToday + amount > dailyWithdrawalLimit || amount > balance) return false;
        balance -= amount;
        withdrawnToday += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n) : userID(id), name(n) {}

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    double checkBalance() const {
        return wallet.getBalance();
    }
};

int main() {
    User u1("01", "Kazim");
    u1.deposit(5000);
    u1.withdraw(2000);
    cout << u1.checkBalance() << endl;

    User u2("02", "Vivek");
    u2.deposit(11000);
    u2.withdraw(6000);
    cout << u2.checkBalance() << endl;

    return 0;
}

