// https://projecteuler.net/problem=7
// Output: 104743
// Time: 0.7s
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int checkAgainstKnownPrimesMethod(int n) {
    vector<int> primes = {2};

    for (int i = 3; primes.size() < n; i++) {
        bool is_prime = true;

        for (const int prime : primes) {
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

    return primes[n - 1];
}

int dynamicSizedSieveMethod(int n) {
    long sieve_size = 200000;
    vector<bool> is_prime(sieve_size, true);
    is_prime[0] = is_prime[1] = false;

    int num_found = 0;
    int largest_prime_found = -1;

    for (long i = 2; num_found < n; i++) {
        if (i >= sieve_size) {
            sieve_size *= 2;
            is_prime.resize(sieve_size, true);

            for (int j = 2; j * j < sieve_size; j++) {
                if (is_prime[j]) {
                    for (int k = j * j; k < sieve_size; k += j) {
                        is_prime[k] = false;
                    }
                }
            }
        }

        if (is_prime[i]) {
            num_found++;
            largest_prime_found = i;

            for (long j = i * i; j <= sieve_size; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return largest_prime_found;
}

int main() {
    int n = 10001;
    cout << checkAgainstKnownPrimesMethod(n) << endl;
}