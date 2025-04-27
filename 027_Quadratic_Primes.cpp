// https://projecteuler.net/problem=27
// Output: -59231
// Time: 0.5s
#include <iostream>
using namespace std;

int numConsecutivePrimes(int a, int b);
bool isPrime(int n);

int main() {
  int maxPrimes = 0;
  int product = 0;

  for (int a = -999; a < 1000; ++a) {
    for (int b = -1000; b <= 1000; ++b) {
      int numPrimes = numConsecutivePrimes(a, b);

      if (numPrimes > maxPrimes) {
        maxPrimes = numPrimes;
        product = a * b;
      }
    }
  }

  cout << product << endl;
}

int numConsecutivePrimes(int a, int b) {
  int n = 0;

  while (isPrime((n * n) + (a * n) + b)) {
    n++;
  }

  return n;
}

bool isPrime(int n) {
  if (n < 2) {
    return false;
  }

  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0)
      return false;
  }

  return true;
}
