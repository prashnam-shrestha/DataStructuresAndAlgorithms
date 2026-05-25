#include <iostream>
using namespace std;
 
bool isPrime(int n) {

    if (n == 1) {
        return false;
    }
    int divisorCount = 0;

    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisorCount ++;
        }
    }
    return divisorCount == 1;
} 

int main() {

    cout << isPrime(1);
    return 0;
}