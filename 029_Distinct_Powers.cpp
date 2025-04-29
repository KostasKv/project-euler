// https://projecteuler.net/problem=29
// Output: 9183
// Time: 0.5s
#include <cmath>
#include <iostream>
#include <set>
using namespace std;

int main() {
  set<double> distinctPowers;

  for (int a = 2; a <= 100; ++a) {
    for (int b = 2; b <= 100; ++b) {
      distinctPowers.insert(pow(a, b));
    }
  }

  cout << distinctPowers.size() << endl;
}