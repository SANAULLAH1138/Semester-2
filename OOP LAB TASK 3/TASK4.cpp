#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Employee {
    string F_name;
    string L_name;
    double monthly_salary;

public:
  
    string getF_name() { return F_name; }
    string getL_name() { return L_name; }
    double getmonthly_salary() { return monthly_salary; }

    void setEmpdata(string F, string L, double MS) {
        F_name = F;
        L_name = L;
        if (MS < 0) 
		{
            monthly_salary = 0.0;
            cout << "Invalid salary!" << endl;
        } else 
		{
            monthly_salary = MS;
        }
    }

    void calc() 
	{
        double YS = monthly_salary * 12;
        cout << "Employee: " << F_name << " " << L_name << endl;
        cout << "Monthly Salary: $" << monthly_salary << endl;
        cout << "Yearly Salary: $" << YS << endl;
        cout<<"***************************************"<<endl;
        
    }
};

int main(int argc, char* argv[]) 
{
    if (argc < 4) 
	{
        cout << "ERROR: Please provide First Name, Last Name, and Monthly Salary as arguments." << endl;
        return 1;
    }  
    string F_name = argv[1];
    string L_name = argv[2];
    double monthly_salary = stod(argv[3]); 

   
    Employee ob1 , ob2;
    ob1.setEmpdata(F_name, L_name, monthly_salary);
    ob1.calc(); 
    
    cout << "Enter details for second employee:\n";
    string F_name2;
	string L_name2;
    double monthly_salary2;

    cout << "First Name: ";
    cin >> F_name2;
    cout << "Last Name: ";
    cin >> L_name2;
    cout << "Monthly Salary: ";
    cin >> monthly_salary2;

    ob2.setEmpdata(F_name2, L_name2, monthly_salary2);
    ob2.calc();
   
}

