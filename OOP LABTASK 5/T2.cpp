#include <iostream>
using namespace std;
const int MAX_CARS = 10;  

class Car {
    string name;
    int ID;

public:
    Car(string n, int id) : name(n), ID(id) {
        cout << "Car constructor called for " << name << endl;
    }

    int getID() {
        return ID;
    }

    string getName() {
        return name;
    }

    ~Car() {
        cout << "Car Destructor Called  " << name << endl;
    }
};

class Garage {
    Car* cars[MAX_CARS];  
    int carCount;         

public:
    Garage() : carCount(0) {
        cout << "Garage Constructor Called" << endl;
    }

    void parkCar(Car* car) {
        if (carCount < MAX_CARS) {
            cars[carCount++] = car;
            cout << car->getName() << " Parked In The Garage.\n";
        } else {
            cout << "Garage Is full! Cannot park " << car->getName() << ".\n";
        }
    }

    void listCars() {
        if (carCount == 0) {
            cout << "No cars in the garage.\n";
            return;
        }
        cout << "Cars in the garage:\n";
        for (int i = 0; i < carCount; i++) {
            cout << "Name: " << cars[i]->getName() << "\tID: " << cars[i]->getID() << endl;
        }
    }

    ~Garage() {
        cout << "Garage Destructor called" << endl;
    }
};

int main() {
    Car c1("CIVICS", 12);
    Car c2("CITY", 13);
    Car c3("BMW", 14);
    Car c4("TESLA", 15);

    Garage garage;
    garage.parkCar(&c1);
    garage.parkCar(&c2);
    garage.parkCar(&c3);
    garage.parkCar(&c4);

    cout << "\nListing Cars In the Garage:\n";
    garage.listCars();

    return 0;
}

