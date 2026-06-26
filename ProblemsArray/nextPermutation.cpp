#include <iostream>
using namespace std;

void reverseFunction(vector<int> &nums, int left, int right) {
    while (left < right) {
        swap(nums[left], nums[right]);
        left ++;
        right --;
    }
}

void nextPermutation(vector<int> &nums) {
    int size = nums.size();

    int breakingPoint = -1;
    int replace = INT_MAX;
    int replaceIndex = -1;

    for (int i = size - 1; i > 0; i--) {
        if (nums[i] > nums[i-1]) {
            breakingPoint = i - 1;
            break;
        }
    }
    if (breakingPoint == -1) {
        // Return the reversed one'
        reverseFunction(nums, 0, size - 1);
        return;
    }

    for (int i = size - 1; i > breakingPoint; i--) {
        if (nums[i] > nums[breakingPoint]) {
            if (nums[i] < replace) {
                replace = nums[i];
                replaceIndex = i;
            }
        }
    }
    swap(nums[breakingPoint], nums[replaceIndex]);
    reverseFunction(nums, breakingPoint + 1, size - 1);
}

int main() {

    vector<int> nums = {2,1,5,4,3,0,0};
    nextPermutation(nums);

    for (auto i: nums) {
        cout << i << " ";
    }
    return 0;
}