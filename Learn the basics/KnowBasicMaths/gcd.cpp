#include <iostream>
using namespace std;

// Better approach O(min(n1, n2));
int gcd(int n1, int n2) {
    int r = min(n1, n2);

    while (r > 0) {
        if (n1 % r == 0 && n2 % r == 0) {
            return r;
        }
        r--;
    }
    return 1;
}

// Best approach Euclidean Algorithm

int gcd2(int n1, int n2) {
    if (n1 == 0 || n2 == 0) {
        return n1 + n2; // edge case;
    }

    int gcd; 
    int a = max(n1, n2);
    int b = min(n1, n2);
    int r = a % b;

    if (r == 0) {
        return b; // edge case;
    }
    while(r > 0) {
        gcd = r;
        a = b;
        b = r;
        r = a % b;
    }
    return gcd;

}

int main() {

    int n1 = 256;
    int n2 = 0;
    cout << gcd2(n1, n2);

    return 0;
}