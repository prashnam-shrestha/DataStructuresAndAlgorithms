#include <iostream>
using namespace std;

void f(vector<int> &nums) {
    int largestSum = INT_MIN;
    int currentSum = 0;
    int size = nums.size();

    int left = 0;
    int right = 0;

    for (int i = 0; i < size; i++) {
        currentSum += nums[i];

        if (currentSum > largestSum) {
            right = i;
            largestSum = currentSum;

            if (currentSum <= 0) {
                left = i;
            }


        }
        if (currentSum <= 0) { 
            currentSum = 0;
        }
    }

    for (int i = left; i <= right; i++) {
        cout << nums[i] << " ";
    }
    
}



int main() {
   vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};   // classic case, should be a sanity check
    f(nums);
    return 0;
}