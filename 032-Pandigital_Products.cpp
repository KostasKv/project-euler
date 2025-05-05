// https://projecteuler.net/problem=32
// Output: 45228
// Time: 0.5s
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

bool isPandigital(int a, int b, int c) {
  string combined = to_string(a) + to_string(b) + to_string(c);

  if (combined.size() != 9) {
    return false;
  }

  sort(begin(combined), end(combined));

  return combined == "123456789";
}

int main() {
  set<int> products;

  for (int a = 1; a < 100; a++) {
    for (int b = a + 1; b < (10000 / a); b++) {
      int c = a * b;

      if (isPandigital(a, b, c)) {
        products.insert(c);
      }
    }
  }

  int sum = 0;

  for (int product : products) {
    sum += product;
  }

  cout << sum << endl;
}