#include <iostream>
#include <string>
using namespace std;

class Bus;
class student {
    static int student_no;
    int id;
    string name;
    int Transport_card;
    string pick_up;
    Bus *assignedBus;
    int attendence[30];

public:
    student() {
        Transport_card = 0;
        assignedBus = nullptr;
        for (int i = 0; i < 30; i++)
            attendence[i] = 0;
    }

    void PayForTransportion() { Transport_card = 1; }

    void SetValue() {
        cout << "Enter ID Of Student: ";
        cin >> id;
        cout << "Enter Name Of Student: ";
        cin >> name;
        cout << "Enter Pick-up Place For Student: ";
        cin >> pick_up;
    }

    void SetBus(Bus &b);
    int getId() const { return id; }
    int GetTransportCard() const { return Transport_card; }
    string Getpick_up() const { return pick_up; }
    Bus *GetBus() const { return assignedBus; }
    int GetAttendence() const;
    void SetAttendence();
    ~student() {}
};

class Bus {
    static int day;
    string *Stops;
    int NumberOfStops;

public:
    Bus() {}
    Bus(int size, string *ptr) : NumberOfStops(size) {
        Stops = new string[size];
        for (int i = 0; i < size; i++) {
            Stops[i] = ptr[i];
        }
    }

    bool TabCard() { return true; }
    int GetSize() { return NumberOfStops; }
    string *GetsStops() { return Stops; }
    void increDay() { day++; }
    int getDay() { return day; }
    
    ~Bus() { delete[] Stops; }
};

void student::SetBus(Bus &b) { assignedBus = &b; }
int student::GetAttendence() const { return assignedBus ? attendence[assignedBus->getDay()] : 0; }
void student::SetAttendence() { if (assignedBus) attendence[assignedBus->getDay()] = 1; }

int student::student_no = 0;
int Bus::day = 0;

int main() {
    int total_student = 0;
    Bus b[3];
    student *s = nullptr;

    string r1[7] = {
        "Gulshan-e-Iqbal", "Saddar", "Clifton", "Korangi",
        "Shahrah-e-Faisal", "Defence (DHA)", "Malir Cantt"
    };

    string r2[7] = {
        "Clifton", "Burns Road", "Boat Basin", "Bahadurabad",
        "Kashmir Road", "Manzoor Colony", "NIPA"
    };

    string r3[8] = {
        "Hill Park", "Gizri", "Shah Faisal Colony", "Punjab Chowrangi",
        "Port Qasim", "Malir", "Model Colony", "NED University"
    };

    b[0] = Bus(7, r1);
    b[1] = Bus(7, r2);
    b[2] = Bus(8, r3);

    int end1 = 1;
    while (end1) {
        cout << "\nEnter ID (9009 for new Student): ";
        int id;
        cin >> id;

        if (id == 9009) {
            total_student++;
            student *temp = new student[total_student];

            for (int i = 0; i < total_student - 1; i++) {
                temp[i] = s[i];
            }

            temp[total_student - 1].SetValue();

            delete[] s;  
            s = temp;
        } else {
            int i;
            for (i = 0; i < total_student; i++) {
                if (id == s[i].getId()) break;
            }

            if (i < total_student) {
                if (s[i].GetTransportCard()) {
                    int a;
                    cout << "Click any button for attendance: ";
                    cin >> a;

                    if (s[i].GetAttendence()) {
                        s[i].GetBus()->TabCard();
                    } else {
                        s[i].GetBus()->increDay();
                        s[i].GetBus()->TabCard();
                    }
                } else {
                    int pay;
                    cout << "Pay Your Transport fees (1-for paying fees): ";
                    cin >> pay;

                    if (pay == 1) {
                        int foundBus = 0;
                        s[i].PayForTransportion();

                        for (int k = 0; k < 3 && !foundBus; k++) {
                            for (int j = 0; j < b[k].GetSize(); j++) {
                                if (s[i].Getpick_up() == b[k].GetsStops()[j]) {
                                    s[i].SetBus(b[k]);
                                    foundBus = 1;
                                    break;
                                }
                            }
                        }

                        if (!foundBus) {
                            cout << "Wrong bus stop" << endl;
                        }
                    }
                }
            } else {
                cout << "Wrong ID" << endl;
            }
        }

        cout << "Do you want to close this program? (0 - Yes, 1 - No): ";
        cin >> end1;
    }

    delete[] s;  

    return 0;
}

