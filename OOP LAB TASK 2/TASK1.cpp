#include<iostream>
using namespace std;
int main(int argc , char* argv[])
{
	int *arr = new int[argc-1];
//	int arr[argc-1];
	int sum=0;
	for(int i=0;i<argc;i++)
	{
		arr[i-1]=atoi(argv[i]);
	}
	
	for(int i=0;i<argc-1;i++)
	{

		sum=sum + arr[i];
	}
	cout<<"SUM = "<<sum<<endl;
	
}
