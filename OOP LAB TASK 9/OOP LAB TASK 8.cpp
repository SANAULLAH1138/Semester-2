#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    vector<string> bookedPassengers;

    bool isBooked(const string& passengerID) {
        for (const auto& id : bookedPassengers) {
            if (id == passengerID) return true;
        }
        return false;
    }

public:
    Flight(string fn, string dep, string arr, int cap)
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap) {}

    bool bookSeat(const string& passengerID) {
        if (bookedPassengers.size() >= capacity || isBooked(passengerID)) return false;
        bookedPassengers.push_back(passengerID);
        return true;
    }

    bool cancelSeat(const string& passengerID) {
        for (auto it = bookedPassengers.begin(); it != bookedPassengers.end(); ++it) {
            if (*it == passengerID) {
                bookedPassengers.erase(it);
                return true;
            }
        }
        return false;
    }

    bool upgradeSeat(const string& passengerID) {
        return isBooked(passengerID);
    }
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string i, string n) : id(i), name(n) {}

    bool requestBooking(Flight& f) {
        return f.bookSeat(id);
    }

    bool requestCancellation(Flight& f) {
        return f.cancelSeat(id);
    }

    bool requestUpgrade(Flight& f) {
        return f.upgradeSeat(id);
    }
};

int main() {
    Flight f("FL123", "NYC", "LAX", 2);
    Passenger p1("1", "Kazim");
    Passenger p2("2", "Vivek");
    Passenger p3("3", "Jitesh");

    p1.requestBooking(f);
    p2.requestBooking(f);
    p3.requestBooking(f);

    cout << p1.requestUpgrade(f) << endl;
    cout << p3.requestCancellation(f) << endl;

    return 0;
}

