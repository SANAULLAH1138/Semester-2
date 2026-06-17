#include<iostream>
using namespace std;

class Car{
public:
    int ehorse;
    int seats;
    int loud;

    Car():ehorse(100),seats(4),loud(2){}

    void carupgrade()const{
        Car* modify=const_cast<Car*>(this);
        modify->ehorse=200;
        modify->seats=5;
        modify->loud=6;
    }

    void display()const{
        cout<<"Horsepower of Engine : "<<ehorse<<endl;
        cout<<"Total Seat Capacity: "<<seats<<endl;
        cout<<"Number of LoudSpeakers: "<<loud<<endl;
    }
};

int main(){
    Car c;
    cout<<"Before  :\n";
    c.display();
    c.carupgrade();
    cout<<"\nAfter:\n";
    c.display();

}
