#include <iostream>
using namespace std;

void sum(int n, int total) { // O(n)
    if (n < 0) {
        cout << total << endl;
        return;
    }
    sum(n-1, total + n);
}

int sum3(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum3(n - 1);
}

void sum2(int n) { // O(1)
    cout << n * (n+1) / 2 << endl;
}

int main() {

    sum(6, 0);
    return 0;
}