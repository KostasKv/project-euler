// https://projecteuler.net/problem=34
// Output: 40730
// Time: 0.5s
#include <iostream>
using namespace std;

int factorial(int n) {
  int result = 1;

  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

int main() {
  const int FACTORIALS[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
  const int UPPER_LIMIT = 7 * FACTORIALS[9];
  int answer = 0;

  for (int i = 10; i <= UPPER_LIMIT; i++) {
    int digitFactorialSum = 0;
    int number = i;

    while (number > 0) {
      digitFactorialSum += FACTORIALS[number % 10];
      number /= 10;
    }

    if (digitFactorialSum == i) {
      answer += i;
    }
  }

  cout << answer << endl;
}
