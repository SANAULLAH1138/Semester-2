#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main(int argc,char *argv[]){
	int arr[argc - 1];
	for(int i = 1; i < argc; i++){
		arr[i - 1] = stoi(argv[i]);
	}
	
	int sum = 0;
	for(int i = 0; i < argc-1; i++){
		sum += arr[i];
	}
	cout << sum;
	
	return 0;
}
