// https://projecteuler.net/problem=19
// Output: 171
// Time: 0.4s
#include <iostream>
#include <string>
using namespace std;

int main() {
    int sundayCount = 0;

    for (int year = 1901; year <= 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            // Zeller's congruence
            int q = 1; // Day of the month

            int m = month; // Month of the year.
            int adjYear = year;

            if (month < 3) {
                // January and February are counted as months 13 and 14 of previous year
                m += 12;
                adjYear -= 1;
            }
            
            int K = year % 100; // Year of the century
            int J = year / 100; // Zero-based century

            int h = (q + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;

            if (h == 0) {
                sundayCount++;
            }
        }
    }

    cout << sundayCount << endl;

    return 0;
}