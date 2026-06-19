#include <iostream>
using namespace std;

void sort(vector<int> &nums) {
    int countZero = 0;
    int countOne = 0; 
    int countTwo = 0;

    int size = nums.size();

    for (int i = 0; i < size; i++) {
        if (nums[i] == 0) {
           countZero++; 
        }
        else if (nums[i] == 1) {
            countOne++;
        }
        else {
            countTwo++;
        }
    }

    for (int i = 0; i < size; i++) {
        if (i < countZero) {
            nums[i] = 0;
        }
        else if (i < countZero + countOne) {
            nums[i] = 1;
        }
        else {
            nums[i] = 2;
        }
    }
}

void sort2(vector<int> &nums) {
    int size = nums.size();
    int leftBoundary = 0;
    int rightBoundary = size - 1;

    for (int i = 0; i < size; i++) {
        if (i > rightBoundary) {
            return;
        }
        if (nums[i] == 0) {
            swap(nums[i], nums[leftBoundary]);
            leftBoundary++;
        }
        else if (nums[i] == 2) {
            swap(nums[i], nums[rightBoundary]);
            rightBoundary --;
            i--;
            
        }
    }
}

int main() {
    vector<int> nums = {2,0,1};
    sort2(nums);
    for (auto i: nums) {
        cout << i << " ";
    }
    return 0;
}