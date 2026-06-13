#include <iostream>
using namespace std;

void moveZeroEnd(vector<int> & nums) {
    int size = nums.size();

    int i = 0;
    int j = 1;

    while (j < size) {
        if (nums[i] != 0) {
            i++;
        }
        else if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i ++;
        }
        j++;

        
    }
}

int main() {
    vector<int> v1 = {1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    moveZeroEnd(v1);
    for (auto i: v1) {
        cout << i << " ";
    }
    return 0;
}