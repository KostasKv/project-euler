// https://projecteuler.net/problem=15
// Output: 137846528820
// Time: 0.6s
#include <iostream>
#include <vector>
using namespace std;

long long choose(int n, int k);

int main() {
    int n = 20;
    cout << choose(20 * 2, 20) << endl;
}

long long choose(int n, int k) {
    return k == 0 ? 1 : n * choose(n - 1, k - 1) / k;
}
