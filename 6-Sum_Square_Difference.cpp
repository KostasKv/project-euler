// https://projecteuler.net/problem=6
// Output: 25164150
// Time: 0.4s
#include <iostream>
#include <cmath>
using namespace std;

int brute_force(int n) {
    int sum_of_squares = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum_of_squares += i * i;
        sum += i;
    }

    return abs(sum_of_squares - (sum * sum));
}

int analytical(int n) {
    int sum_of_squares = n * (n + 1) * (2*n + 1) / 6;
    int sum = n * (n + 1) / 2;    
    return abs(sum_of_squares - sum * sum);
}

int main() {
    int n = 100;
    cout << analytical(n) << endl;
}