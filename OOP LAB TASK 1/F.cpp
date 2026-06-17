#include <iostream>
using namespace std;

float 2ndMax(float arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            float first = arr[i];
            float second = arr[j];
            if (first > second) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr[size - 2];
}

int main(int argc, char* argv[]) {
    

    float arr[argc-1];
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = stof(argv[i]);
    }

    float high2 = 2ndMax(arr, 20);
    cout << high2 << endl;

    return 0;
}
