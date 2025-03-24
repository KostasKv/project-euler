// https://projecteuler.net/problem=3
// Output: 6857
// Time: 0.5s
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long n = 600851475143;
    int largest_prime = 1;

    while (n % 2 == 0) {
        largest_prime = 2;
        n /= 2;
    }
    
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            largest_prime = i;
            n /= i;
        }
    }
    
    if (n > 2) {
        largest_prime = n;
    }

    cout << largest_prime << endl;
}