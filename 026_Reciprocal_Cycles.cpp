// https://projecteuler.net/problem=26
// Output: 983
// Time: 0.5s
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int calculateCycleLength(int denominator);

int main() {
  const int LIMIT = 1000;
  int d = 0;
  int maxLength = 0;

  for (int i = 2; i < LIMIT; ++i) {
    int length = calculateCycleLength(i);

    if (length > maxLength) {
      maxLength = length;
      d = i;
    }
  }

  cout << d << endl;
}

int calculateCycleLength(int denominator) {
  unordered_map<int, int> remainderPositions;
  int remainder = 1;
  int position = 0;

  while (remainder != 0) {
    remainder = remainder % denominator;

    if (remainderPositions.find(remainder) != remainderPositions.end()) {
      return position - remainderPositions[remainder];
    }

    remainderPositions[remainder] = position;

    remainder *= 10;
    position++;
  }

  return 0;
}