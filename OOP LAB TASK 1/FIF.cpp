#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

int main(){
	string arr[6] = {
	"Movie Name :",
	"Number of ticket sold:",
	"Gross Amount:",
	"Percentage of Gross amount donates:",
	"Amount Donated:",
	"Net Sale:"
	};
	
	int maxLength = arr[3].length();
	string name;
	cout << "Enter movie name : ";
	cin >> name;
	int adultTickSold;
	cout << "Enter the number of Adult ticket sold :";
	cin >> adultTickSold;
	int childTickSold;
	cout << "Enter the child ticket sold : ";
	cin >> 	childTickSold;
	float childTickPrice, adultTickPrice;
	cout << "Enter the child ticket price :";
	cin >> childTickPrice;
	cout << "ENter the adult ticket price";
	cin >> adultTickPrice;
	float percent;
	cout << "Enter the percent to be donated : ";
	cin >> percent;
	int totalTicketsold = childTickSold + adultTickSold;
	float gross = (childTickSold * childTickPrice) + (adultTickSold * adultTickPrice);
	float amountDonated = (percent*gross)/100;
	float netSale = gross - amountDonated;
	system("cls");
	float outputarr[6] = {
		0, totalTicketsold,gross,percent,amountDonated,netSale
	};
	for(int i = 0; i < 6; i++)
	{
		cout << arr[i];
		if(arr[i].length() < maxLength)
		{
			for(int j = arr[i].length(); j < maxLength; j++)
			{
				cout << ".";
			}
		}
		if(i == 0)
		{
			cout << name;
		}else
		{
			printf("%.2f",outputarr[i]);
		}
		cout << endl;
		
	}
	return 0;
}
