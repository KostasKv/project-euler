// https://projecteuler.net/problem=1
// Output: 233168
// Time: 0.7s
#include <iostream>
#include <cmath>
using namespace std;

int sumMultiplesOfUpTo(int k, int max) {
    int largest_multiple = max - (max % k);
    int number_of_terms_in_sum = largest_multiple / k;
    return (k + largest_multiple) * number_of_terms_in_sum  / 2;
}

int main() {
    int n = 999;
    cout << sumMultiplesOfUpTo(3, n) + sumMultiplesOfUpTo(5, n) - sumMultiplesOfUpTo(15, n) << endl;
}