#include <iostream>
using namespace std;

bool armstrong(int n) {
    int goal = n;
    int total = 0;
    int digits = to_string(n).length();
    
    while (n > 0) {
        total += pow(n % 10, digits);
        n = n/10;
    }
    return total == goal;
}

int main() {
    cout << armstrong(37);
}
