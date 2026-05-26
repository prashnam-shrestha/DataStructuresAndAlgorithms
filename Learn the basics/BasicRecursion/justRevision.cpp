#include <iostream>
using namespace std;

void f(int count) {
    if (count == 4) {
        return;
    }
    count++;
    cout << count << endl;
    f(count);
}

int main() {
    f(0);
    return 0;
}