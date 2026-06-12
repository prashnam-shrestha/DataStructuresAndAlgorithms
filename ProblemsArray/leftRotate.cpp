#include <iostream>
using namespace std;

void rotate(vector<int>& nums, int rotate) {
    vector<int> copy = nums;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        nums[i] = copy[(i + rotate) % size];
    }
    
}

void rotate2(vector<int>& nums, int k) {

    k = k%nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void leftByOne(vector<int> &nums) {
    int size = nums.size();
    int first = nums[0];
    for (int i = 0; i < (size - 1); i++) {
        nums[i] = nums[i+1];
    }
    nums[size-1] = first;
}

int main() {

    vector<int> v2 = {1,2,3,4,5,6,7};
    rotate2(v2, 8);
    for (auto i: v2){
        cout << i << " ";
    }
    return 0;
}