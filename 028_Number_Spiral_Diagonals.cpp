// https://projecteuler.net/problem=28
//  Output: 669171001
//  Time: 0.6s
#include <iostream>
using namespace std;

int main() {
  const int SIZE = 1001;
  long long sum = 1;
  int num = 1;

  for (int layer = 1; layer <= SIZE / 2; layer++) {
    int stepSize = layer * 2;

    for (int i = 0; i < 4; i++) {
      num += stepSize;
      sum += num;
    }
  }

  cout << sum << endl;
}