#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode, currencySymbol;
    double exchangeRate;
public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    virtual double convertToBase() = 0;
    double convertTo(Currency &targetCurrency) {
        double base_amount = convertToBase();
        return base_amount / targetCurrency.exchangeRate;
    }
    virtual void displayCurrency() = 0;
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    double convertToBase() override {
        return amount;
    }
    void displayCurrency() override {
        cout << currencySymbol << amount << "\n";
    }
};

class Euro : public Currency {
public:
    Euro(double amt, double rate) : Currency(amt, "EUR", "€", rate) {}
    double convertToBase() override {
        return amount * exchangeRate;
    }
    void displayCurrency() override {
        cout << currencySymbol << amount << "\n";
    }
};

int main() {
    Dollar usd(100);
    Euro eur(92, 1.4);
    
    usd.displayCurrency();
    eur.displayCurrency();
    
    cout << "Converted to USD: " << eur.convertTo(usd) << " USD\n";
    cout << "Converted to EUR: " << usd.convertTo(eur) << " EUR\n";
    
    return 0;
}

