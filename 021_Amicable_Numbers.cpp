// https://projecteuler.net/problem=21
// Output: 31626
// Time: 0.4s
#include <iostream>
using namespace std;

int sumProperDivisors(int n);

int main() {
    const int limit = 10000;
    int answer = 0;

    for (int a = 2; a < limit; ++a) {
        int b = sumProperDivisors(a);

        if (a != b && b < limit && sumProperDivisors(b) == a) {
            answer += a;
        }
    }

    cout << answer << endl;

    return 0;
}

int sumProperDivisors(int n) {
    int sum = 1;

    for (int i = 2; (i * i) <= n; ++i) {
        if (n % i == 0) {
            sum += i;

            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum;
}