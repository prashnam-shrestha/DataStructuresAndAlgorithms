#include <iostream>
using namespace std;
vector<int> leaderArray2(vector<int> &nums) {
    vector<int> leaders;
    int size = nums.size();
    int highest = INT_MIN;
    for (int i = size - 1; i >= 0; i--) {
        if (nums[i] > highest) {
            leaders.push_back(nums[i]);
            highest = nums[i];
        }
    }
    return leaders;
}

vector<int> leaderArray(vector<int> &nums) {
    vector<int> leaders;
    int size = nums.size();

    for (int i = size - 1; i >= 0; i--) {
        bool isLeader = true;
        int num = nums[i];


        for (int j = i + 1; j < size; j++) {
            if (nums[i] <= nums[j]) {

                isLeader = false;
                break;
            }
        }
        if (isLeader) {
            leaders.push_back(nums[i]);
        }
    }
    return leaders;
}

int main() {
    vector<int> nums ={4, 7, 1, 0};
    vector<int> leaders = leaderArray2(nums);
    for (auto i: leaders) {
        cout << i << " ";
    }
    return 0;
}