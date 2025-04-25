// https://projecteuler.net/problem=24
// Output: 2783915460
// Time: 0.5s
#include <iostream>
using namespace std;

void nextPermutation(string &str);

int main() {
  const int target = 1000000;
  string digits = "0123456789";
  int count = 1;

  while (count < target) {
    nextPermutation(digits);
    count++;
  }

  cout << digits << endl;
}

void nextPermutation(string &str) {
  int n = str.size();
  int i = n - 2;

  while (i >= 0 && str[i] >= str[i + 1]) {
    i--;
  }

  int j = n - 1;
  while (str[j] <= str[i]) {
    j--;
  }

  swap(str[i], str[j]);
  reverse(str.begin() + i + 1, str.end());
}