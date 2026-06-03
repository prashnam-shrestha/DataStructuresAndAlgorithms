#include <iostream>
using namespace std;

void insertSort(int array[], int size) {

    for (int i = 0; i < size; i++) {
        int right = i;
        int left = right - 1;

        while(left >= 0) {
            if (array[right] < array[left]) {
                swap(array[right], array[left]);
            }
            else {
                break;
            }
            right--;
            left--;
        }

    }
}

int main() {
    
    int array[] = {3, -1, 3, 0, -2};
    insertSort(array, 5);

    for (auto i: array) {
        cout << i << " ";
    }
    return 0;
}
