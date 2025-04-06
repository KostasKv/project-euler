// https://projecteuler.net/problem=16
// Output: 1366
// Time: 0.5s
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> reverseDigits;
    reverseDigits.push_back('1');

    for (int i = 0; i < 1000; i++) {
        int carry = 0;
        
        for (int j = 0; j < reverseDigits.size(); j++) {
            int digit = reverseDigits[j] - '0';
            
            int sum = 2 * digit + carry;
            
            reverseDigits[j] = (char)((sum % 10) + '0');
            carry = (int) sum >= 10;
        }

        if (carry) {
            reverseDigits.push_back('1');
        }
    }

    int digitSum = 0;

    for (char digit : reverseDigits) {
        digitSum += digit - '0';
    }

    cout << digitSum << endl;
}
