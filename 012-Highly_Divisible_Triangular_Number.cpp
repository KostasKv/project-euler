// https://projecteuler.net/problem=12
// Output: 76576500 
// Time: 0.5s
#include <iostream>
#include <cmath>
using namespace std;

int triangleNum(int n) {
    return n * (n + 1) / 2;
}

int main() {
    int t, numFactors;
    const int LIMIT = 500;

    for (int i = 1; ; i++) {
        t = triangleNum(i);
        numFactors = 2; // 1 and t are both factors of t

        for (int j = 2; j < sqrt(t); j++) {
            if (t % j == 0) {
                if (j == sqrt(t)) {
                    numFactors++;
                } else {
                    numFactors += 2;
                }
            }
        }

        if (numFactors > LIMIT) {
            break;
        }
    }

    cout << t << endl;
}
