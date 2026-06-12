#include <iostream>
#include <set>
using namespace std;

void removeDuplicates(vector<int> &nums) {
    int size = nums.size();
    int left = 0;
    for (int i = 0; i < (size); i++) {
        if (nums[left] < nums[i+1]) {
            swap(nums[left + 1], nums[i+1]);
            left++;
        }
    }
    cout << left + 1 << " ." << endl;
}

int main() {
    vector<int> v1 = {1,2,3,4,5};
    removeDuplicates(v1);
    for (auto i: v1) {
        cout << i << " ";
    }
    return 0;
}