#include <iostream>
using namespace std;

void print(int times) {
    if (times == 0) {
        return;
    }
    cout << times << endl;
    print(times - 1);
    
}

int main() {

    print(4);
    return 0;
}