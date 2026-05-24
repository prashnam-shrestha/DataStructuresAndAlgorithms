#include <iostream>
using namespace std;

int reverseNum(int n) {
    int a = 0;
    while (n > 0) {
        // n % 10 gets the last digit
        a = a * 10 + n % 10;
        
        // n / 10 removes the last digit
        n = n / 10;
    }
    return a;
}

int main() {

    int num = 39;
    cout << reverseNum(num);

    return 0;
}