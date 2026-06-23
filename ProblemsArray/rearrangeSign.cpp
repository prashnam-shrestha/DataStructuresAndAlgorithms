#include <iostream>
#include <queue>
using namespace std;

void rearrangeSign(vector<int> &nums) {
    queue<int> negativeStock;
    queue<int> positiveStock;

    int size = nums.size();

    for (int i = 0; i < size; i++) {
        if (nums[i] >= 0) {
            positiveStock.push(nums[i]);
        }
        else {
            negativeStock.push(nums[i]);
        }
    }
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            nums[i] = positiveStock.front();
            positiveStock.pop();
        }
        else {
            nums[i] = negativeStock.front();
            negativeStock.pop();
        }
    }

}

int main() {
    vector<int> nums = {1,2,3,-1,-2,-3};
    rearrangeSign(nums);
    for (auto i: nums) {
        cout << i << " ";
    }

    return 0;
}