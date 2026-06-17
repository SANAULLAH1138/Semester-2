#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int MAX = 100;

struct Employee {
    int id;
    string name;
    string designation;
    int years;
};

Employee parseLine(const string& line) {
    stringstream ss(line);
    string idStr, name, designation, yearsStr;
    getline(ss, idStr, ',');
    getline(ss, name, ',');
    getline(ss, designation, ',');
    getline(ss, yearsStr, ',');
    Employee emp;
    emp.id = stoi(idStr);
    emp.name = name;
    emp.designation = designation;
    emp.years = stoi(yearsStr);
    return emp;
}

string toLine(Employee emp) {
    return to_string(emp.id) + "," + emp.name + "," + emp.designation + "," + to_string(emp.years);
}

void saveToFile(const string& filename, Employee emps[], int count) {
    ofstream file(filename);
    for (int i = 0; i < count; i++) {
        file << toLine(emps[i]) << endl;
    }
    file.close();
}

int loadFromFile(const string& filename, Employee emps[]) {
    ifstream file(filename);
    string line;
    int count = 0;
    while (getline(file, line) && count < MAX) {
        emps[count++] = parseLine(line);
    }
    file.close();
    return count;
}

int main() {
    Employee allEmps[MAX];
    Employee filtered[MAX];
    int totalCount = 0, filteredCount = 0;

    ofstream file("employees.txt");
    file << "1,Ali,Manager,3\n";
    file << "2,Sara,Developer,1\n";
    file << "3,Zain,Manager,2\n";
    file << "4,Ayesha,Intern,1\n";
    file << "5,Usman,Manager,1\n";
    file.close();

    totalCount = loadFromFile("employees.txt", allEmps);

    for (int i = 0; i < totalCount; i++) {
        if (allEmps[i].designation == "Manager" && allEmps[i].years >= 2) {
            filtered[filteredCount++] = allEmps[i];
        }
    }

    cout << "Filtered Managers with >=2 years:\n";
    for (int i = 0; i < filteredCount; i++) {
        cout << toLine(filtered[i]) << endl;
    }

    saveToFile("employees.txt", filtered, filteredCount);
    cout << "\nFile overwritten with filtered data.\n";

    for (int i = 0; i < filteredCount; i++) {
        filtered[i].id += 100;
        filtered[i].years += 1;
    }
    saveToFile("employees.txt", filtered, filteredCount);
    cout << "Updated data with incremented IDs and years saved.\n";

 \
}

