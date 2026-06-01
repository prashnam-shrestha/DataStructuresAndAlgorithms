#include <iostream>
using namespace std;
int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int sumOfFactorials(int n){ // O(n^2)

    int total = 1;
    if (n == 1) {
        return n;
    }

    return factorial(n) + sumOfFactorials(n-1);

}

int main() {

    cout << sumOfFactorials(10);
    return 0;
}