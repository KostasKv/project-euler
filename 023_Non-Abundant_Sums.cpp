// https://projecteuler.net/problem=23
// Output: 4179871
// Time: 0.6s
#include <iostream>
#include <vector>
using namespace std;

int sumOfDivisors(int n);

int main() {
  const int LIMIT = 28123;

  vector<int> abundants;
  for (int i = 1; i <= LIMIT; ++i) {
    if (sumOfDivisors(i) > i) {
      abundants.push_back(i);
    }
  }

  vector<bool> isSumOfAbundant(LIMIT + 1, false);
  for (int i = 0; i < abundants.size(); ++i) {
    for (int j = i; j < abundants.size(); ++j) {
      int sum = abundants[i] + abundants[j];

      if (sum <= LIMIT) {
        isSumOfAbundant[sum] = true;
      } else {
        break;
      }
    }
  }

  long long answer = 0;
  for (int i = 1; i <= LIMIT; ++i) {
    if (!isSumOfAbundant[i]) {
      answer += i;
    }
  }

  cout << answer << endl;
}

int sumOfDivisors(int n) {
  int sum = 1;

  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      sum += i;

      if (i != n / i) {
        sum += n / i;
      }
    }
  }

  return sum;
}