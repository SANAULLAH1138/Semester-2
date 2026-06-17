#include <iostream>
#include <string>
using namespace std;

class BigInteger {
private:
    string digits;
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.length() > 1 && digits[0] == '0')
            digits.erase(0, 1);
        if (digits == "0")
            isNegative = false;
    }

public:
    BigInteger(string s = "0") {
        isNegative = false;
        if (s[0] == '-') {
            isNegative = true;
            s = s.substr(1);
        }
        digits = s;
        removeLeadingZeros();
    }

    BigInteger operator+(const BigInteger& other) const {
        string a = digits;
        string b = other.digits;
        string result = "";
        int carry = 0;
        int i = a.length() - 1, j = b.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            result = char(sum % 10 + '0') + result;
        }

        return BigInteger(result);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& b) {
        if (b.isNegative) os << "-";
        os << b.digits;
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& b) {
        string s;
        is >> s;
        b = BigInteger(s);
        return is;
    }
};
