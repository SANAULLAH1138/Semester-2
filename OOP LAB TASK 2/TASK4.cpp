#include<iostream>
using namespace std;

struct employee {
    string name;
    int id;
    int salary;
};

struct organization {
    string name;
    string num;
    struct employee emp;
};

int main() {
    organization org;
    employee emp;
    emp.name = "FAST";
    emp.id = 101;
    emp.salary = 25000;

    org.name = "NU-FAST";
    org.num = "NUFAST123";
    org.emp = emp; // Assign the employee instance to the organization

   
    cout << "Organization Name: " << org.name << endl;
    cout << "Organization Number: " << org.num << endl;
    cout << "Employee Name: " << org.emp.name << endl;
    cout << "Employee ID: " << org.emp.id << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;

    return 0;
}
