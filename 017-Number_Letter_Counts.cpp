// https://projecteuler.net/problem=16
// Output: 21124
// Time: 0.4s
#include <iostream>
#include <string>
using namespace std;

string numberToSpacelessWords(int num) {
    if (num == 0) {
        return "Zero";
    }
    
    string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                          "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    
    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    
    string result;
    
    if (num >= 1000) {
        result += ones[num / 1000] + "Thousand";
        num %= 1000;
    }
    
    if (num >= 100) {
        result += ones[num / 100] + "Hundred";
        num %= 100;

        if (num > 0) {
            result += "and";
        }
    }
    
    if (num >= 20) {
        result += tens[num / 10] + "";
        num %= 10;
    }
    
    if (num > 0) {
        result += ones[num] + "";
    }
    
    return result;
}

int main() {
    int sum = 0;
    
    for (int i = 1; i <= 1000; i++) {
        string words = numberToSpacelessWords(i);
        sum += words.length();
    }
    
    cout << sum << endl;
    
    return 0;
}
