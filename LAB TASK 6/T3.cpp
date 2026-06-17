#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual ~Employee() = default; 
};

class IOrderTaker {
public:
    virtual void takeOrder(const vector<string>& items) = 0;
    virtual ~IOrderTaker() = default;
};

class IOrderPreparer {
public:
    virtual void prepareOrder(int orderId) = 0;
    virtual ~IOrderPreparer() = default;
};

class IBiller {
public:
    virtual void generateBill(int orderId) = 0;
    virtual ~IBiller() = default;
};


class Menu {
public:
    virtual double calculateTotal(const vector<string>& items) const {
        return items.size() * 10.0;
    }
    virtual ~Menu() = default;
};

class FoodMenu : public Menu {
public:
    double calculateTotal(const vector<string>& items) const override {
        return items.size() * 8.5; 
    }
};

class BeverageMenu : public Menu {
public:
    double calculateTotal(const vector<string>& items) const override {
        return items.size() * 3.5 * 1.1; 
    }
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, string n) : Employee(i, n) {}

    void takeOrder(const vector<string>& items) override {
        cout << "Waiter " << name << " took order for:\n";
        for (const auto& item : items) cout << "- " << item << "\n";
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, string n) : Employee(i, n) {}

    void prepareOrder(int orderId) override {
        cout << "Chef " << name << " preparing order #" << orderId << "\n";
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int i, string n) : Employee(i, n) {}

    void generateBill(int orderId) override {
        cout << "Cashier " << name << " generated bill for order #" << orderId << "\n";
    }
};


class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int i, string n) : Employee(i, n) {}

    void takeOrder(const vector<string>& items) override {
        cout << "Manager " << name << " took special order for:\n";
        for (const auto& item : items) cout << "- " << item << "\n";
    }

    void generateBill(int orderId) override {
        cout << "Manager " << name << " approved bill for order #" << orderId << "\n";
    }
};

int main() {
    Waiter john(1, "John");
    Chef mike(2, "Mike");
    Cashier lisa(3, "Lisa");
    Manager bob(4, "Bob");

    vector<string> order = {"Burger", "Fries"};
    
    john.takeOrder(order);
    mike.prepareOrder(101);
    lisa.generateBill(101);
    
    bob.takeOrder({"Steak", "Wine"});
    bob.generateBill(102);

    FoodMenu food;
    BeverageMenu drinks;
    
    cout << "Food total: $" << food.calculateTotal(order) << "\n";
    cout << "Drinks total: $" << drinks.calculateTotal({"Soda", "Water"}) << "\n";

    return 0;
}

