#include <iostream>
#include <cmath>

using namespace std;

int countDigitsBrute(int n) {

    int count = 0;
    if (n == 0) {
        return 1;
    }
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;

    // Time complexity is log10N because it simply is
}

int countDigitOptimal(int n) {
    if (n == 0) {
        return 1;
    }
    return log10(n) + 1;
    // Time complexity is O(1) because cpu and perform - 
    // - log10(n) fast in its builtin ALU
}

int main() {
    int n = 231;
    cout << countDigitsBrute(n) <<  endl;
    cout << countDigitOptimal(n) << endl;

    return 0;
}