#include <iostream>
using namespace std;

int majorityElement(vector<int> &nums) {

    int candidate;
    int count = 0;
    int size = nums.size();

    for (int i = 0; i < size; i++) {
        if (count == 0) {
            candidate = nums[i];
            count++;
        }
        else if(nums[i] == candidate) {
            count++;
        }
        else{
            count --;
        }
    }

    return candidate;
}

int main() {

    return 0;
}