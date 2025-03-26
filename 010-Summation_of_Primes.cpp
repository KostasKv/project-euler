// https://projecteuler.net/problem=10
// Output: 142913828922
// Time: 1.0s
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int main() {
    const int NUM_PRIMES_LIMIT = 2000000;
    vector<int> primes;
    bool is_prime;

    primes.push_back(2);

    for (int i = 3; i < NUM_PRIMES_LIMIT; i++) {
        is_prime = true;

        for (const auto& prime : primes) {
            if (prime > sqrt(i)) {
                break;
            }

            if (i % prime == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            primes.push_back(i);
        }
    }

    long sum = std::accumulate(begin(primes), end(primes), 0L, plus<>());
    cout << sum << endl;
}