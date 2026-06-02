#include <iostream>
using namespace std;

void selectionSort(int array[], int size) {
    int left = 0;
    int right = 0;
    while (left < size-1) {

        int index = left;

        while(right <= size-1) {
            if (array[right] < array[index]) {
                index = right;
            }
            right++;
        }
        // SWAP
    
        swap(array[left], array[index]);
        left++;
        right = left;

        
    }
}

int main() {

    int array[] = {1, 2, 3, 4, 5};
    selectionSort(array, 5);
    for (auto i: array) {
        cout << i << endl;
    }
    return 0;
}