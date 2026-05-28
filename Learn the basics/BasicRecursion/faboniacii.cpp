#include <iostream>
using namespace std;

int f(int n) {

    // Base case;
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    return f(n-1) + f(n-2);

}

int main() {

    cout << f(11);
    return 0;
}