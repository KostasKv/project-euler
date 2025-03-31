// https://projecteuler.net/problem=14
// Output: 837799
// Time: 1.1s
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<long long, int> collatzLengths;
    int maxLength = 0;
    int startingNumberForLongestChain = 0;

    collatzLengths[1] = 1;

    for (int i = 3; i < 1000000; i += 2) {
        long long term = i;
        int length = 0;

        while (term > 1 && collatzLengths.find(term) == end(collatzLengths)) {
            bool isEven = term % 2 == 0;
            term = isEven ? (term / 2) : ((3 * term) + 1);
            length++;
        }

        length += collatzLengths[term];
        collatzLengths[i] = length;

        if (length > maxLength) {
            maxLength = length;
            startingNumberForLongestChain = i;
        }            
        }
    
    cout << startingNumberForLongestChain << endl;
}