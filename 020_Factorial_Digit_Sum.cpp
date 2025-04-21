// https://projecteuler.net/problem=20
// Output: 648
// Time: 0.4s
#include <iostream>
#include <vector>
using namespace std;

vector<int> getFactorial(int number);

int main() {
    int digitSum = 0;

    for (int digit : getFactorial(100)) {
        digitSum += digit;
    }

    cout << digitSum << endl;

    return 0;
}

vector<int> getFactorial(int number) {
    vector<int> factorial = {1};

    for (int i = 2; i <= number; ++i) {
        int carry = 0;

        for (int j = 0; j < factorial.size(); ++j) {
            int product = factorial[j] * i + carry;
            
            factorial[j] = product % 10;
            carry = product / 10;
        }

        while (carry > 0) {
            factorial.push_back(carry % 10);
            carry /= 10;
        }
    }

    return factorial;
}