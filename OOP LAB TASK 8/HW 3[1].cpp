#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int empID;
public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    virtual void displayData() {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
    string name;
    float income;
public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> income;
    }

    float bonus() const {
        return income * 0.05f * 12;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << "\nIncome: " << income << "\nBonus: " << bonus() << endl;
    }
};

class Accounts : public Person {
    string name;
    float income;
public:
    void getData() override {
        Person::getData();
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Monthly Income: ";
        cin >> income;
    }

    float bonus() const {
        return income * 0.05f * 12;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << "\nIncome: " << income << "\nBonus: " << bonus() << endl;
    }
};
