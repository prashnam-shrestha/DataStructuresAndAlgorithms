#include <iostream>
using namespace std;

int maxSumSubArray(vector<int> &nums, int k) {
    int max = INT_MIN;
    int size = nums.size();

    if (size < k) {
        return -1;
    }

    int num = nums[0];

    for (int i = 1; i < k; i++) {
        num += nums[i];
    }
    max = num;

    for (int i = k; i < size; i++) {
        num += nums[i];
        num -= nums[i-k];

        if (num > max) {        
            max = num;
        }
    }
    return max;

}

int main() {
    vector<int> nums = {2, 1,5,9};
    int k = 3;
    cout << maxSumSubArray(nums, k);
    return 0;
}