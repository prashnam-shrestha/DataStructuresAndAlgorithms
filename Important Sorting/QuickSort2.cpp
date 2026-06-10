#include <iostream>
using namespace std;

void quickSort(vector<int>& v1, int low, int high) {
    if (high <= low) {
        return;
    }
    int pivot = v1[low];
    int left = low + 1;
    int right = high;

    while (left < right) {
        while(v1[left] <= pivot && left <= high) {
            left++;
        }
        while(v1[right] > pivot && right >= low + 1){
            right--;
        }
        if (left < right) {
            swap(v1[left], v1[right]);
        }
        
        
    }
    swap(v1[low], v1[right]);

    quickSort(v1, low, right - 1);
    quickSort(v1, right + 1, high);
}

int main(){

    vector<int> v1 = {5,-4,-1,1,28,6,2,0,93};
    quickSort(v1, 0, v1.size() - 1); 
    for (auto i: v1) {
        cout << i << " ";
    }
    return 0;
}