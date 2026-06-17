#include <iostream>
#include <string>
using namespace std;

class User {
public:
    string name;
    int age;
    string licenseType;
    string contact;
    int userID;

    User(string n, int a, string l, string c, int id) : name(n), age(a), licenseType(l), contact(c), userID(id) {}

    void updateDetails(string n, int a, string l, string c) {
        name = n;
        age = a;
        licenseType = l;
        contact = c;
    }

    void displayUser() {
        cout << "User ID: " << userID << "\nName: " << name << "\nAge: " << age << "\nLicense: " << licenseType << "\nContact: " << contact << endl;
    }
};

class Vehicle {
public:
    string model;
    float rentalPrice;
    string requiredLicense;

    Vehicle(string m, float p, string r) : model(m), rentalPrice(p), requiredLicense(r) {}

    void displayVehicle() {
        cout << "Model: " << model << " ,price per day: " << rentalPrice << " ,required License: " << requiredLicense << endl;
    }

    bool isEligible(string userLicense) {
        return userLicense == requiredLicense || (requiredLicense == "Learner" && userLicense != "None");
    }
};

class RentalSystem {
private:
    Vehicle **vehicles;
    int vehicleCount;

public:
    RentalSystem(int count) {
        vehicleCount = count;
        vehicles = new Vehicle *[vehicleCount];
    }

    void addVehicle(int index, string model, float price, string license) {
        vehicles[index] = new Vehicle(model, price, license);
    }

    void displayAvailableVehicles() {
        cout << "\nAvailable Vehicles: " << endl;
        for (int i = 0; i < vehicleCount; i++) {
            vehicles[i]->displayVehicle();
        }
    }

    void rentVehicle(User &user, int vehicleIndex) {
        if (vehicleIndex < 0 || vehicleIndex >= vehicleCount) {
            cout << "Invalid vehicle selection." << endl;
            return;
        }
        if (vehicles[vehicleIndex]->isEligible(user.licenseType)) {
            cout << "\nRental Successful! " << user.name << " rented "
                 << vehicles[vehicleIndex]->model << " for " << vehicles[vehicleIndex]->rentalPrice << " per day." << endl;
        } else {
            cout << "\nRental Failed! You do not have the required license to rent " << vehicles[vehicleIndex]->model << endl;
        }
    }

    ~RentalSystem() {
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicles[i];
        }
        delete[] vehicles;
    }
};

int main() {
    cout << "SANAULLAH (24K-0954)" << endl;
    cout << "-----------------------------------------------------------" << endl << endl;

    User user("SANAULLAH", 21, "Full", "897-346-4560", 1);
    user.displayUser();

    RentalSystem s(3);
    s.addVehicle(0, "TESLA", 2500, "Learner");
    s.addVehicle(1, "Honda Civic", 5000, "Intermediate");
    s.addVehicle(2, "BMW X5", 10000, "Full");
    s.displayAvailableVehicles();

    int choice;
    cout << "\nEnter vehicle index to rent (0-2): ";
    cin >> choice;
    s.rentVehicle(user, choice);
    
    return 0;
}

