#include <iostream>
using namespace std;

int findLargest(int arr[], int size) {
    if (size <= 0) {
        return 0;
    }
    int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {

    int arr[5] = {2, 5, 1, 3, 0};
    cout << findLargest(arr, 5) << endl;
    return 0;
}
 