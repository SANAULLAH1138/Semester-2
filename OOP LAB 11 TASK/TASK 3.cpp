#include <iostream>
#include <stdexcept>

using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "ArrayIndexOutOfBounds: Invalid index accessed.";
    }
};

template<typename T>
class SafeArray {
    T* arr;
    size_t size;
public:
    SafeArray(size_t sz) : size(sz) {
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || static_cast<size_t>(index) >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    SafeArray<int> sa(5);
    try {
        sa[0] = 10;
        sa[4] = 20;
        cout << sa[0] << endl;
        cout << sa[4] << endl;
        cout << sa[5] << endl;
    } catch (const ArrayIndexOutOfBounds& e) {
        cout << e.what() << endl;
    }
    return 0;
}

