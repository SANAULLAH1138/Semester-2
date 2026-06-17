#include <iostream>
#include <cstdlib>  
using namespace std;

void* Add(void* ptr, int num) 
{
    int* arr = static_cast<int*>(ptr);  
    for(int i = 0; i < num; i++) 
	{
        arr[i] = arr[i]+10; 
    }
    return ptr;  // Return the modified array
}

int main(int argc, char* argv[]) 
{
    int num = argc - 1;
    int* arr = new int[num];  // Dynamically allocate memory for the array  
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
  
    arr = (int*)Add((void*)arr, num); 
    cout << "Modified Array: ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  
    return 0;
}
