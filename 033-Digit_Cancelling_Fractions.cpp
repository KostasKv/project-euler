// https://projecteuler.net/problem=33
// Output: 100
// Time: 0.4s
#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
  int numeratorsProduct = 1;
  int denominatorsProduct = 1;

  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      for (int k = 1; k < 10; k++) {
        int numerator = 10 * i + j;
        int denominator = 10 * j + k;

        if (i != k && numerator * k == denominator * i) {
          numeratorsProduct *= numerator;
          denominatorsProduct *= denominator;
        }
      }
    }
  }

  int result =
      denominatorsProduct / gcd(numeratorsProduct, denominatorsProduct);

  cout << result << endl;
}