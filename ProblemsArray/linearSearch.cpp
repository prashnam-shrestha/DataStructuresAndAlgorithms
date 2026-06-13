#include <iostream>
using namespace std;

int linearSearch(vector<int> & nums, int target) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<int> v1 = {1,2,3,4,5};
    cout << linearSearch(v1, 3);
    return 0;
}