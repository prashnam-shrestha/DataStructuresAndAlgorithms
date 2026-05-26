#include <iostream>
using namespace std;

void print(int times, int num) {
    cout << num << endl;
    if (num == times) {
        return;
    }
    num++;
    print(times, num);
}

int main() {

    print(4, 1);
    return 0;
}