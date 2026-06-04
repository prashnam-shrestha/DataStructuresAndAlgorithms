#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeSort(vector<int>& arr, int left, int right) {
    // BASE CASE
    if (left == right) {
        return;
    }


    int middle =  (left + right)/2;
    mergeSort(arr, left, middle);

    mergeSort(arr, middle + 1, right);

    bool sorted = false;

    vector<int> temp;
    vector<int> leftHalf;
    vector<int> rightHalf;
    for (int i = left; i <= middle; i++) {
        leftHalf.push_back(arr[i]);
    }

    for (int i = middle + 1; i <= right; i++) {
        rightHalf.push_back(arr[i]);
    }

    int leftPointer = 0;
    int rightPointer = 0;

    // MERGE AND SORT LEFT HALF AND RIGHT HALF
    while(leftPointer < leftHalf.size() && rightPointer < rightHalf.size()) {
        if (leftHalf[leftPointer] < rightHalf[rightPointer]) {
            temp.push_back(leftHalf[leftPointer]);
            leftPointer++;
        }
        else {
            temp.push_back(rightHalf[rightPointer]);
            rightPointer++;
        }
    }
    while(leftPointer < leftHalf.size()) {
        temp.push_back(leftHalf[leftPointer]);
        leftPointer++;
    }
    while(rightPointer < rightHalf.size()) {
        temp.push_back(rightHalf[rightPointer]);
        rightPointer++;
    }
     // UPDATE MAIN ARRAY
    int k = 0;
    for (int i = left; i <= right; i++) {
        arr[i] = temp[k];
        k++;
    }

}

int main() {

    vector<int> arr = {9,7,4,6,3,8,2};
    mergeSort(arr, 0, 6);

    for (auto i: arr) {
        cout << i << " ";
    }
    return 0;
}