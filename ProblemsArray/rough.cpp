#include <iostream>
using namespace std;

void largestSum(vector<int> &nums) {
    int size = nums.size();
    int max = INT_MIN;
    int sum = 0;
    int start = 0;
    int realStart;
    int realEnd;
    for (int i = 0; i < size; i++) {

        if (sum == 0) {
            start = i;
        }

        sum += nums[i]; 
        if (sum <= 0) {
            sum = 0;
        }
        if (sum > max) {
            max = sum;
            realStart = start;
            realEnd = i;
        }


    }
    for (int i = realStart; i <= realEnd; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    cout << max;
}

int main() {
    vector<int> nums = {-3,-2,-1,4,-1,2,-90};
    largestSum(nums);
}