#include <iostream>
using namespace std;

void printName(int n, string name, int times) {
    
    if (times == n) {
        return;
    }
    times++;
    printName(n, name, times);
    cout << name << endl;
}

int main() {
    printName(4, "Prashnam", 0);
    
    return 0;
}