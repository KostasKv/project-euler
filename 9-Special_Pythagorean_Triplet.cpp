// https://projecteuler.net/problem=9
// Output: 31875000
// Time: 0.5s
#include <iostream>
#include <cmath>
using namespace std;

int findAnswer(int n) {
    float c;

    for (int a = 1; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            c = sqrt(a*a + b*b);

            if (c != floor(c) || c <= b) {
                continue;
            }

            if ((a + b + c) == n) {
                return a * b * c;
            }
        }
    }

    return -1;
}

int main() {
    int n = 1000;
    cout << findAnswer(n) << endl;
}