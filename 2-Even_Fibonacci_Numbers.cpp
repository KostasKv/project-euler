// https://projecteuler.net/problem=2
// Output: 4613732
// Time: 0.1s
#include <iostream>
#include <vector>
using namespace std;

int even_fibonacci(int n, int memo[]) {
    if (n == 0) return 0;
    if (n == 1) return 2;
    if (memo[n] != -1) return memo[n];

    return memo[n] = 4 * even_fibonacci(n - 1, memo) + even_fibonacci(n - 2, memo);
}

int main() {
    int memo[100000];
    fill_n(memo, 100000, -1);

    const int MAX = 4000000;
    int sum = 0;

    for (int i = 0, fib; (fib = even_fibonacci(i, memo)) <= MAX ; i += 1) {
        sum += fib;
    }

    cout << sum << endl;
}
