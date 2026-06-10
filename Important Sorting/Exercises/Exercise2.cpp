#include <iostream>
using namespace std;

int partitionFunction(vector<int>& v1, int low, int high) {
    int pivot = v1[low];

    int left = low + 1;
    int right = high;

    while (left <= right) {
        while(v1[left] <= pivot && left <= high) {
            left++;
        }
        while(v1[right] > pivot && right >= low + 1) {
            right--;
        }
        if (left <= right) {
            swap(v1[left], v1[right]);
        }

    }
    swap(v1[low], v1[right]);
    return right;
}

int main() {
   vector<int> v1 = {4, 6, 4, 2, 7, 1, 4};
   cout << partitionFunction(v1, 0, v1.size() - 1) << endl;
   for (auto i: v1) {
    cout << i << " ";
   }

    return 0;
}