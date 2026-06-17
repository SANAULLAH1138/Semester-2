#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException: Stack is empty.";
    }
};

template<typename T>
class Stack {
    vector<T> elements;
public:
    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (elements.empty())
            throw StackUnderflowException();
        elements.pop_back();
    }

    T top() const {
        if (elements.empty())
            throw StackUnderflowException();
        return elements.back();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    Stack<int> s;
    try {
        s.push(10);
        s.push(20);
        cout << s.top() << endl;
        s.pop();
        cout << s.top() << endl;
        s.pop();
        s.pop();
    } catch (const StackUnderflowException& e) {
        cout << e.what() << endl;
    }
    return 0;
}

