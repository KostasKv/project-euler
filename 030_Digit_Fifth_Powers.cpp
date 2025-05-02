// https://projecteuler.net/problem=30
// Output: 443839
// Time: 0.4s
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  const int MAX = 6 * pow(9, 5);
  int totalSum = 0;

  for (int i = 2; i <= MAX; ++i) {
    int sum = 0;
    int num = i;

    while (num > 0) {
      int digit = num % 10;
      num /= 10;

      sum += pow(digit, 5);
    }

    if (sum == i) {
      totalSum += i;
    }
  }

  cout << totalSum << endl;
}