// https://projecteuler.net/problem=25
// Output: 4782
// Time: 0.5s
#include <iostream>
#include <vector>
using namespace std;

vector<int> add(const vector<int> &a, const vector<int> &b);

int main() {
  const int LIMIT = 1000;

  vector<int> fib1 = {1};
  vector<int> fib2 = {1};
  int i = 2;

  for (; fib2.size() < LIMIT; i++) {
    vector<int> nextFib = add(fib1, fib2);
    fib1 = fib2;
    fib2 = nextFib;
  }

  cout << i << endl;
}

vector<int> add(const vector<int> &a, const vector<int> &b) {
  vector<int> result;
  int carry = 0;
  int sum = 0;
  size_t maxSize = max(a.size(), b.size());

  for (size_t i = 0; i < maxSize || carry; ++i) {
    sum = carry;

    if (i < a.size()) {
      sum += a[i];
    }

    if (i < b.size()) {
      sum += b[i];
    }

    result.push_back(sum % 10);
    carry = sum / 10;
  }

  return result;
}