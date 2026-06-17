#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(string m) : model(m), price(0.0) {}

    string getModel() const {
        return model;
    }

    double getPrice() const {
        return price;
    }

    void setModel(string m) {
        model = m;
    }

    virtual void setPrice(double p) = 0; 

    virtual void display() const = 0; 
};

class Color : public Car {
private:
    string color;

public:
    Color(string m, string c) : Car(m), color(c) {}

    void setPrice(double p)  {
        if (color == "Red")
            price = p + 2000;
        else
            price = p + 1000;
    }

    void display() const override {
        cout << "Model: " << model << ", Color: " << color << ", Price: $" << price << endl;
    }
};

class Company : public Car {
private:
    string company;

public:
    Company(string m, string comp) : Car(m), company(comp) {}

    void setPrice(double p) override {
        if (company == "Toyota")
            price = p + 5000;
        else
            price = p + 3000;
    }

    void display() const override {
        cout << "Model: " << model << ", Company: " << company << ", Price: $" << price << endl;
    }
};

int main() {
    Color c1("Sedan", "Red");
    c1.setPrice(20000);
    c1.display();

    Company c2("SUV", "Toyota");
    c2.setPrice(25000);
    c2.display();

    return 0;
}

