#include <iostream>
using namespace std;

int reverseNum(int n) {
    bool negative = false;
    if (n < 0) {
        negative = true;
        n = n * -1;
    }
    
    int a = 0;
    while (n != 0) {
        if (a > INT32_MAX / 10 || a < INT32_MIN / 10) {
            return 0;
        }
        // n % 10 gets the last digit
        a = a * 10 + n % 10;
        
        // n / 10 removes the last digit
        n = n / 10;
    }
    if (negative) {
        return a * -1;
    }
    return a;
}

int main() {

    int num = -39;
    cout << reverseNum(num);

    return 0;
}