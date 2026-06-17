#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int id;
    double salary;

public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
    }

    virtual void displayData() const {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }

    virtual void bonus() const {
        cout << "Bonus: " << salary * 0.1 << endl; 
    }

    virtual ~Person() {} 
};

class Admin : virtual public Person {
public:
    void getData() override {
        cout << "[Admin Info]\n";
        Person::getData();
    }

    void displayData() const override {
        cout << "[Admin Display]\n";
        Person::displayData();
    }

    void bonus() const override {
        cout << "Admin Bonus: " << salary * 0.15 << endl;
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        cout << "[Account Info]\n";
        Person::getData();
    }

    void displayData() const override {
        cout << "[Account Display]\n";
        Person::displayData();
    }

    void bonus() const override {
        cout << "Account Bonus: " << salary * 0.12 << endl; 
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "[Master Info]\n";
        Person::getData(); 
    }

    void displayData() const override {
        cout << "[Master Display]\n";
        Person::displayData();
    }

    void bonus() const override {
        cout << "Master Bonus: " << salary * 0.20 << endl; 
    }
};

int main() {
    Person* p;  

    Admin m;
    p = &m;

    p->getData();
    p->displayData();
    p->bonus();

    return 0;
}

