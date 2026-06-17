#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual double getTuition(const string& status, int creditHours) = 0; 
    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    double getTuition(const string& status, int creditHours) override {
        if (status == "undergraduate")
            return creditHours * 200;
        else if (status == "graduate")
            return creditHours * 300;
        else if (status == "doctoral")
            return creditHours * 400;
        else {
            cout << "Invalid status!" << endl;
            return 0;
        }
    }
};

int main() {
    GraduateStudent grad;
    grad.setResearchTopic("Artificial Intelligence");

    string status;
    int hours;

    cout << "Enter student status (undergraduate, graduate, doctoral): ";
    cin >> status;

    cout << "Enter number of credit hours: ";
    cin >> hours;

    double tuition = grad.getTuition(status, hours);
    cout << "\nResearch Topic: " << grad.getResearchTopic() << endl;
    cout << "Tuition for " << hours << " hours as a " << status << " student: $" << tuition << endl;

    return 0;
}

