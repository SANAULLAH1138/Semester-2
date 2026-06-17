#include <iostream>
using namespace std;

class Student{
private:
    const int roll_no;
public:
    Student(int r):roll_no(r){
	}
	
    void showData(){
        cout<<"Student Roll No: "<<roll_no<<endl;
    }
};


int main(){
    int r;
    cout<<"Enter Roll No: ";
    cin>>r;
    Student s(r);
    s.showData();
}
