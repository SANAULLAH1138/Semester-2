#include <iostream>
#include <any>
#include <stdexcept>
#include <typeinfo>

class BadTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Incorrect type requested.";
    }
};

class TypeSafeContainer {
    std::any data;
public:
    template<typename T>
    void store(const T& value) {
        data = value;
    }

    template<typename T>
    T get() const {
        if (!data.has_value() || data.type() != typeid(T)) {
            throw BadTypeException();
        }
        return std::any_cast<T>(data);
    }
};

