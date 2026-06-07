#include <iostream>
using namespace std;

void recursiveBubbleSort(vector<int>& v1, int end) { // O(N^2)
    if (end == 0) {
        return;
    }
    for(int i = 0; i < end - 1; i++) {
        if (v1[i] > v1[i + 1]) {
            swap(v1[i], v1[i + 1]);
        }
    }
    recursiveBubbleSort(v1, end - 1);
}

int main() {
    vector<int> v1 = {9,24,292,-5,7,1,-12,0,-1,763,2,9999,92,992};
    recursiveBubbleSort(v1, v1.size());
    for(auto i: v1) {
        cout << i << " ";
    }
}