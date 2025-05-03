// https://projecteuler.net/problem=31
// Output: 73682
// Time: 0.4s
#include <iostream>
using namespace std;

int main() {
  const int TWO_POUNDS = 200;
  const int COINS[] = {1, 2, 5, 10, 20, 50, 100, 200};
  const int NUM_COINS = 8;

  int ways[TWO_POUNDS + 1] = {0};
  ways[0] = 1;

  for (int i = 0; i < NUM_COINS; ++i) {
    for (int j = COINS[i]; j <= TWO_POUNDS; ++j) {
      ways[j] += ways[j - COINS[i]];
    }
  }

  cout << ways[TWO_POUNDS] << endl;
}