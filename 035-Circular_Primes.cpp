// https://projecteuler.net/problem=35
// Output: 55
// Time: 2.4s
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generatePrimes(vector<bool> &isPrime, int limit);
vector<int> generateRotations(int n);
bool isCircularPrime(int n, vector<bool> &isPrime);

int main() {
  int count = 0;
  const int LIMIT = 1000000;
  vector<bool> isPrime(LIMIT, true);
  generatePrimes(isPrime, LIMIT);

  for (int i = 2; i < LIMIT; i++) {
    if (isCircularPrime(i, isPrime)) {
      count++;
    }
  }

  cout << count << endl;
}

void generatePrimes(vector<bool> &isPrime, int limit) {
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i < limit; i++) {
    for (int j = i * i; j < limit; j += i) {
      isPrime[j] = false;
    }
  }
}

bool isCircularPrime(int n, vector<bool> &isPrime) {
  vector<int> rotations = generateRotations(n);

  for (int rotatedNum : rotations) {
    if (!isPrime[rotatedNum]) {
      return false;
    }
  }

  return true;
}

vector<int> generateRotations(int n) {
  vector<int> rotations;
  string num = to_string(n);
  int len = num.size();

  for (int i = 0; i < len; i++) {
    rotate(begin(num), begin(num) + 1, end(num));
    rotations.push_back(stoi(num));
  }

  return rotations;
}
