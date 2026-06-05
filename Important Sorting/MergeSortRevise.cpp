#include <iostream>
using namespace std;

void mergeSort(vector<int>& v1, int low, int high) {
    // DIVIDE
    int middle = (low + high)/2;
    if (low == high) {
        return;
    }
 
    mergeSort(v1, low, middle);
    mergeSort(v1, middle+1, high);
    // MERGE 
    vector<int> temp;

    int left1 = low;
    int right1 = middle;

    int left2 = middle + 1;
    int right2 = high;

    // SORT WITHIN THE RANGE
    while (left1 <= right1 && left2 <= right2) {
        if(v1[left1] < v1[left2]) {
            temp.push_back(v1[left1]);
            left1++;
        }
        else {
            temp.push_back(v1[left2]);
            left2++;
        }
    }
    while (left1 < left2) {
        temp.push_back(v1[left1]);
        left1++;
    }
    while (left2 <= right2) {
        temp.push_back(v1[left2]);
        left2++;
    }

    // COPY THE SORTED PART
    int k = 0;
    for (int i = low; i <= high; i++) {
        v1[i] = temp[k];
        k++;
    }


}

int main() {
    vector<int> v1 = {5,4,2,5,2,1};
    mergeSort(v1, 0, 5);

    for (auto i: v1) {
        cout << i <<  " ";
    }

    return 0;
}