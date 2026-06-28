#include <iostream>
using namespace std;

void quickSort(vector<int>& v1, int low, int high) {
    if (low >= high)
        return;

    int pivot = v1[low];
    int left = low + 1;
    int right = high;

    while (left <= right) {

        while (left <= high && v1[left] <= pivot)
            left++;

        while (right >= low + 1 && v1[right] > pivot)
            right--;

        if (left < right)
            swap(v1[left], v1[right]);
    }

    swap(v1[low], v1[right]);

    quickSort(v1, low, right - 1);
    quickSort(v1, right + 1, high);
}
 
int longestCons(vector<int> &nums) {
    int max = 1;
    int current = 1;
    int size = nums.size();
    if (size <= 0) {
        return 0;
    }
    quickSort(nums, 0, size - 1);

    for (int i = 0; i < size - 1; i++) {
        
        if (nums[i] == nums[i + 1] - 1) {
            
            current++;
            if (current > max) {
                max = current;
        }   }
        else if (nums[i] != nums[i + 1]) {
            current = 1;
        }
    }
    return max;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestCons(nums);

}