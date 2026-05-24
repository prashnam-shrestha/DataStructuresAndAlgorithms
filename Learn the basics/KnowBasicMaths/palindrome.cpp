#include <iostream>
using namespace std;

bool palindromeNum(int n) {
    int nonReversed = n;
    int reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n = n/10;
    }

    return reversed == nonReversed;
}

int main() {

    int a = 101;
    cout << palindromeNum(a);
    return 0;
}