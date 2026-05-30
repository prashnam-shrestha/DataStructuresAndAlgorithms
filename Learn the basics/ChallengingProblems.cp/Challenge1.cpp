#include <iostream>
using namespace std;

int main() {
    // O(Size of arr)
    int arr[] = {2, 3, 3, 3, 4, 4, 4, 4};
    unordered_map<int, int> frequency;

    for (auto i: arr) {
        frequency[i]++;
    }
    int output = -1;

    for (auto i: frequency) {
        if (i.first == i.second && i.first > output) {
            output = i.first;
        }
    }

    cout << output << endl;

    return 0;

}