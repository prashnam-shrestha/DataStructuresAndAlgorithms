#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size; i++) {

        bool swappedOnce = false;

        for (int j = 0; j < (size - i) - 1; j++) {

            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swappedOnce = true;
            }

        }
        if (!swappedOnce) {
            break;
        }
    }
}

int main() {

    int array[] = {3, -2, 3, -5, 0};
    bubbleSort(array, 5);
    for (auto i: array) {
        cout << i << " ";
    }
    return 0;
}
