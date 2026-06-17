#include <iostream>
#include <string>
using namespace std;

class PatientRecord {
private:
    string name;
    string id;
    string dob;
    string medicalHistory;
    string billingInfo;

public:
    PatientRecord(string n, string i, string d) : name(n), id(i), dob(d) {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + id;
    }

    string getMedicalData(const string& role) const {
        if (role == "Doctor") 
		return medicalHistory;
        return "Access Denied";
    }

    void updateMedicalHistory(const string& role, const string& history) {
        if (role == "Doctor") medicalHistory = history;
    }

    void addBillingDetails(const string& role, const string& billing) {
        if (role == "Billing") billingInfo = billing;
    }

    string getBillingDetails(const string& role) const {
        if (role == "Billing") return billingInfo;
        return "Access Denied";
    }
};

int main() {
    PatientRecord p("Sanaullah", "P01", "2025-01-01");
    p.updateMedicalHistory("Doctor", "Diabetes");
    p.addBillingDetails("Billing", "$2000");

    cout << p.getPublicData() << endl;
    cout << p.getMedicalData("Doctor") << endl;
    cout << p.getBillingDetails("Billing") << endl;
    cout << p.getMedicalData("Receptionist") << endl;
    return 0;
}

