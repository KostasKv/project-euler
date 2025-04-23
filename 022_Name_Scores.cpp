// https://projecteuler.net/problem=22
// Output: 871198282
// Time: 0.5s
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<string> names;
    string name;
    ifstream file("022_names.txt");

    while (getline(file, name, ',')) {
        name.erase(remove(begin(name), end(name), '\"'), end(name));
        names.push_back(name);
    }

    file.close();
    sort(begin(names), end(names));

    long long total = 0;
    for (size_t i = 0; i < names.size(); ++i) {
        int score = 0;

         for (char c : names[i]) {
            score += (c - 'A' + 1);
        }

        total += (i + 1) * score;
    }

    cout << total << endl;
}