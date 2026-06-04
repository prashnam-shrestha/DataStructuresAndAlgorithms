#include <iostream>
#include <algorithm>

using namespace std;



vector<int> mergeSort(vector<int> v1) {
    // Base case; 
    if (v1.size() <= 1) {
        return v1;
    }
    
    // Get the index
    int low = 0;
    int high = v1.size() - 1;
    int middle = (high + low)/ 2;

    
    // Divide it into two vectors
    vector<int> leftHalf(v1.begin(), v1.begin() + middle + 1);
    vector<int> rightHalf(v1.begin() + middle + 1, v1.begin() + high + 1);

    vector<int> sortedLeft = mergeSort(leftHalf);
    vector<int> sortedRight = mergeSort(rightHalf);

    // Conquer
    vector<int> mergedSorted(sortedLeft.size() + sortedRight.size());
    merge(sortedLeft.begin(), sortedLeft.end(),
        sortedRight.begin(), sortedRight.end(),
        mergedSorted.begin());


    return mergedSorted;
}

int main() {

    vector<int> v1 = {9, 3, 5, 2, 6, 8, 4};
    vector<int> sortedV1 = mergeSort(v1);

    for (auto i: sortedV1) {
        cout << i << " ";
    }
}