#include <iostream>
using namespace std;

int f(int n) {
    // O(Log10 N) ?? kinda confused recursion + log10 N??
    if (n < 10) {
        return n;
    }
    int nCopy = n;
    int sum = 0;
    while (nCopy > 0) {
        sum += nCopy % 10;
        nCopy = nCopy/10;
    }
    return f(sum);
}

int main() {
    
    int n = 123456789;
    cout << f(n);
    return 0;
}