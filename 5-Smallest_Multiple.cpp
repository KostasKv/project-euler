// https://projecteuler.net/problem=5
// Output: 232792560
// Time: 0.5s
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

// Returns all primes up to n using sieve of Eratosthenes
vector<int> sievePrimesUpto(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}

int main() {
    int n = 20;
    
    vector<int> primes = sievePrimesUpto(n);
    map<int, int> primes_to_occurences_needed;

    // Calculate highest power of each prime occuring amongst all prime-factorisations of numbers up to n
    for (int i = 2; i <= n; i++) {
        int num = i;

        for (const int prime: primes) {
            if (prime > num) break;

            int count = 0;

            while (num % prime == 0) {
                num /= prime;
                count ++;
            }

            primes_to_occurences_needed[prime] = max(count, primes_to_occurences_needed[prime]);
        }
    }

    int lowest_common_multiple = 1;
    
    // Lowest common multiple of integers [1, n] is the product of the primes to their highest power calculated above
    for (const auto& [prime, count] : primes_to_occurences_needed) {
        lowest_common_multiple *= pow(prime, count);
    }

    cout << lowest_common_multiple << endl;
}