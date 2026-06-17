#include <iostream>
using namespace std;

class Person {
protected:
    string name, address, phoneNumber, email;
    int id;
public:
    Person(string n, int i, string addr, string phone, string mail) {
        name = n;
        id = i;
        address = addr;
        phoneNumber = phone;
        email = mail;
    }
    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }
};

class Student : public Person {
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, int i, string addr, string phone, string mail, string courses, double gpa, int year)
        : Person(n, i, addr, phone, mail), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses: " << coursesEnrolled << "\nGPA: " << GPA << "\nEnrollment Year: " << enrollmentYear << endl;
    }
    string getName() { return name; }
};

class Professor : public Person {
    string department, coursesTaught;
    double salary;
public:
    Professor(string n, int i, string addr, string phone, string mail, string dept, string courses, double sal)
        : Person(n, i, addr, phone, mail), department(dept), coursesTaught(courses), salary(sal) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nCourses Taught: " << coursesTaught << "\nSalary: " << salary << endl;
    }
};

class Staff : public Person {
    string department, position;
    double salary;
public:
    Staff(string n, int i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}
    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: " << salary << endl;
    }
};

class Course {
    int courseId;
    string courseName, instructor, schedule;
    int credits;
public:
    Course(int id, string name, int cred, string instr, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(instr), schedule(sched) {}
    void registerStudent(Student &s) {
        cout << "Student " << s.getName() << " registered in " << courseName << endl;
    }
};

int main() {
    Student s("Kazim", 11, "12-C Street", "0936473210", "KAzim@mail.com", "Physics , Science", 3.8, 2022);
    Professor p("Vivek", 98, "45 Avenue", "098754342", "Vivek@mail.com", "Physics", "Quantum Mechanics", 80000);
    Staff st("Sanaullah", 34, "79 Boulevard", "453727134", "Itsme@mail.com", "Admin", "Clerk", 40000);
    Course c(501, "Mathematics", 3, "Prof. Areb", "Mon-Thur 10 AM");
    
    s.displayInfo();
    cout << "---------------------" << endl;
    p.displayInfo();
    cout << "---------------------" << endl;
    st.displayInfo();
    cout << "---------------------" << endl;
    c.registerStudent(s);
    
    return 0;
}
