#include <iostream>
using namespace std;

int secondLargest(vector<int> v1) {
    if (v1.size() < 2) {
        return -1;
    }
    int largest = INT_MIN;
    int secondLargest = INT_MIN; 
    // Throne technique

    for (auto i: v1) {
        if (i > largest) {
            secondLargest = largest;
            largest = i;
        }
        // Edge case
        if (i > secondLargest && i < largest) {
            secondLargest = i;
        }
    }

    // Edge case
    if (secondLargest == INT_MIN) {
        return -1;
    }
    return secondLargest;
}

int main() {
    vector<int> v1 = {10,10,10,10};
    cout << secondLargest(v1);
    return 0;
}