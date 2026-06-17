#include <iostream>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    int balance;
    bool isFreez;

public:
    BankAccount(string AN, int b) : accountNumber(AN), balance(b), isFreez(false) {}

    virtual ~BankAccount() {}  

    virtual void deposit(int amount) {
        balance += amount;
    }

    void withdraw(int amount) {  
        if (isFreez) {
            cout << "Account is frozen. Cannot withdraw.\n";
            return;
        }
        if (balance - amount < 0) {
            cout << "Not sufficient balance.\n";
            return;
        }
        balance -= amount;
        cout << "New balance: " << balance << endl;
    }

    void freeze() {
        isFreez = true;
        cout << "Account has been frozen.\n";
    }

    void unfreeze() {
        isFreez = false;
        cout << "Account has been unfrozen.\n";
    }

    int getBalance() const { return balance; }
};

class SavingAccount : public BankAccount {
protected:
    float mInterest;

public:
    SavingAccount(string AN, int b, float MI) : BankAccount(AN, b), mInterest(MI) {}

    void setMinterest(float MI) {
        mInterest = MI;
    }
};

class CheckingAccount : public BankAccount {
protected:
    int overDraftLimit;

public:
    CheckingAccount(string AN, int b, int ODL) : BankAccount(AN, b), overDraftLimit(ODL) {}

    void setOverDraftLimit(int ODL) {
        overDraftLimit = ODL;
    }
};

class BuisnessAccount : public BankAccount {
protected:
    int corporateTax;

public:
    BuisnessAccount(string AN, int b, int CT) : BankAccount(AN, b), corporateTax(CT) {}

    void deposit(int amount) override {  
        if (balance + amount - corporateTax <= 0) {
            balance = 0;
            return;
        }
        balance += amount - corporateTax;
    }

    void setCorporateTax(int CT) {
        corporateTax = CT;
    }
};

class Customer {
public:
    void deposit(BankAccount &acc, int amount) {
        acc.deposit(amount);
    }

    void withdraw(BankAccount &acc, int amount) {
        acc.withdraw(amount);
    }
};

class Teller : public Customer {
public:
    void freezeAccount(BankAccount &acc) {
        acc.freeze();
    }

    void unfreezeAccount(BankAccount &acc) {
        acc.unfreeze();
    }
};

class Manager : public Teller {
public:
    void changeOverDraftLimit(CheckingAccount &acc, int newODL) {
        acc.setOverDraftLimit(newODL);
    }

    void changeCorporateTax(BuisnessAccount &acc, int newCT) {
        acc.setCorporateTax(newCT);
    }

    void changeMonthlyInterest(SavingAccount &acc, float newMI) {
        acc.setMinterest(newMI);
    }
};

int main() {
    SavingAccount sa("SA123", 1000, 2.5);
    CheckingAccount ca("CA456", 2000, 500);
    BuisnessAccount ba("BA789", 5000, 100);

    Customer cust;
    Teller teller;
    Manager mgr;

    cout << "Initial balance in SavingAccount: " << sa.getBalance() << endl;
    cust.deposit(sa, 500);
    cout << "After deposit: " << sa.getBalance() << endl;

    teller.freezeAccount(sa);
    cust.withdraw(sa, 200);
    teller.unfreezeAccount(sa);
    cust.withdraw(sa, 200);  

    cout << "Final balance in SavingAccount: " << sa.getBalance() << endl;

    return 0;
}

