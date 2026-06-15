#include <iostream>
using namespace std;

int appearOnce(vector<int> &nums) {
    // TC: O(N) Ammortized (O(N^2))
    // SC: O(N)
    int size = nums.size();
    unordered_map<int,int> frequency;

    for (int i = 0; i < size; i++) {
        frequency[nums[i]]++;
    }
    for (auto i: frequency) { 
        if (i.second == 1) {
            return i.first;
        }
    }
    return -1;
    
}

int appearOnceBetter(vector<int> &nums) {
    // TC: O(N) Strict;
    // TC: O(1);

    int xOR = 0;
    for (auto i: nums) {
        xOR = xOR ^ i;
    }
    return xOR != 0 ? xOR : -1;
}

int main() {
    vector<int> nums = {4,1,2,1,2};
    cout << appearOnceBetter(nums);
    return 0;
}