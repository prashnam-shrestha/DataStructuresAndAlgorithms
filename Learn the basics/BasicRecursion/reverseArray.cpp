#include <iostream>
using namespace std;

vector<int> reverseArr(vector<int> nums) {

    vector<int> reversed;
    int size = nums.size();
    for (int i = size - 1; i >= 0; i--) {
        reversed.push_back(nums.at(i));
    }
    return reversed;
}

void reverseArrR(vector<int>& nums, int left, int right) {
    
    // Base case
    if (left > right) {
        return;
    }
    swap(nums.at(left), nums.at(right));
    reverseArrR(nums, left + 1, right - 1);
}

int main() {

    vector<int> v = {1,2,3,4,5,6,7,8};
    reverseArrR(v, 0, 7);
    reverse(v.begin(), v.end());
    for (auto i: v) {
        cout << i << endl;
    }
    return 0;
}