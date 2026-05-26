#include <iostream>
using namespace std;

void print(int times) {
    if (times == 0) {
        return;
    }
    print(times - 1);
    cout << times << endl;
}

int main() {

    print(4);
    return 0;
}