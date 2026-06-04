#include <iostream>
using namespace std;

int main() {

    
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < middle - 1; i++) {
            if (arr[left + i] > arr[left + i + 1]) {
                swap(arr[left], arr[right]);
                sorted = false;
            }
        }
        
    }
    return 0;
}