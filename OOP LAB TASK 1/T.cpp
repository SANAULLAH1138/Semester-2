#include<iostream>
using namespace std;
float calcBill(int units){
	float bill;
	
	if(units <= 199){
		bill = 16.29 * units;
	}else if(units > 199 && units < 300){
		bill = 20.10 * units;
	}else if(units >= 300 && units <500){
		bill = 27.10 * units;
	}else{
		bill = 35.90*units;
	}
	return bill;
}

float getamountcharged(int units){
	float amountcharged;
	
	if(units <= 199){
		amountcharged = 16.29;
	}else if(units > 199 && units < 300){
		amountcharged = 20.10 ;
	}else if(units >= 300 && units <500){
		amountcharged = 27.10 ;
	}else{
		amountcharged= 35.90;
	}
	return amountcharged;
}
int main(int argc, char *argv[]){
	
	int id = stoi(argv[1]);
	string name = argv[2];
	int units = stoi(argv[3]);
	
	float bill = calcBill(units);
	float surcharged = 0;
	if(bill > 1800){
		surcharged = bill*0.15;
	}
	int netamount = bill+surcharged;
	float amountcharged = getamountcharged(units);
	cout << "Coustomer ID : " <<id << endl;
	cout << "Coustomer Name : "<<name<<endl;
	cout << "Unit Consumed : " << units << "per unit : "<<bill << endl;
	cout << "Amount Charged : " << amountcharged << endl;
	cout << "Surcharge amount : " << surcharged << endl;
	cout << "Net cmount : " << netamount;
	return 0;
}
