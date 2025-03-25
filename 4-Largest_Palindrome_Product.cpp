// https://projecteuler.net/problem=4
// Output: 906609
// Time: 0.6s
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool is_palindrome(int n) {
    string num = to_string(n);
    
    string rev = num;
    reverse(rev.begin(), rev.end());

    return num == rev;
}

int main() {
    for (int i = (999*999); i >= 100*100; i--) {
        if (is_palindrome(i)) {
            for (int j = 999; j >= 100; j--) {
                if (i % j == 0 && i / j < 1000) {
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }
}