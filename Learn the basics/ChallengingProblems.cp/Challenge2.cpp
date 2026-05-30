#include <iostream>
using namespace std;

int main() {

    // O(Log10 N)
    int n = 104;
    int nCopy = n;
    int count = 0;

    while (nCopy > 0) {
        int digit = nCopy % 10;
        if (digit != 0 && n % digit == 0 ) {
            count++;
        }
        nCopy = nCopy/10;
    }

    cout << count;
    return 0;
}