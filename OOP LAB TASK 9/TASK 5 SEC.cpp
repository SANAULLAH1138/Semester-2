#include <iostream>
using namespace std;

class Wallet {
private:
    float balance;
    float dailyDepositLimit;
    float dailyWithdrawLimit;
    float todayDeposited;
    float todayWithdrawn;

public:
    Wallet() {
        balance = 0;
        dailyDepositLimit = 5000;
        dailyWithdrawLimit = 3000;
        todayDeposited = 0;
        todayWithdrawn = 0;
    }

    void deposit(float amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount" << endl;
            return;
        }
        if (todayDeposited + amount > dailyDepositLimit) {
            cout << "Deposit exceeds daily limit" << endl;
            return;
        }
        balance += amount;
        todayDeposited += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount" << endl;
            return;
        }
        if (todayWithdrawn + amount > dailyWithdrawLimit) {
            cout << "Withdrawal exceeds daily limit" << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient balance" << endl;
            return;
        }
        balance -= amount;
        todayWithdrawn += amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }

    float getBalance() {
        return balance;
    }

    void resetDailyLimits() {
        todayDeposited = 0;
        todayWithdrawn = 0;
        cout << "Daily limits have been reset." << endl;
    }
};

class User {
private:
    int userID;
    string name;
    Wallet wallet;

public:
    User(int id, string n) {
        userID = id;
        name = n;
    }

    void deposit(float amount) {
        cout << name << " attempting to deposit: " << amount << endl;
        wallet.deposit(amount);
    }

    void withdraw(float amount) {
        cout << name << " attempting to withdraw: " << amount << endl;
        wallet.withdraw(amount);
    }

    void checkBalance() {
        cout << "Balance for " << name << ": " << wallet.getBalance() << endl;
    }

    void newDay() {
        wallet.resetDailyLimits();
    }
};

int main() {
    User user1(1, "Ali");
    User user2(2, "Sara");

    user1.deposit(2000);
    user1.withdraw(1000);
    user1.checkBalance();

    cout << "\n--- New User Transactions ---\n" << endl;

    user2.deposit(6000);  // Should fail (over deposit limit)
    user2.deposit(4000);  // Should also fail
    user2.withdraw(5000); // Should fail (over withdraw limit)
    user2.withdraw(2000); // Should fail (insufficient balance)
    user2.checkBalance();

    cout << "\n--- New Day Begins ---\n" << endl;

    user2.newDay(); // Reset limits

    user2.deposit(3000);
    user2.withdraw(1500);
    user2.checkBalance();

    return 0;
}

