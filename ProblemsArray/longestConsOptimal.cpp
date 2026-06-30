#include <iostream>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int> &nums) {

    int max = 1;
    int current = 1;
    if (nums.size() <= 0) {
        return 0;
    }
    unordered_set<int> existence;

    for (auto i: nums) {
        existence.insert(i);
    }
    for (auto i: existence) {

        int num = i;
        if (existence.count(num - 1)) {
            continue;
        }
        while (existence.count(num + 1)) {
            current ++;
            num++;
        }

        if (current > max) {
            max = current;
        }
        current = 1;
    }
    return max;
}

int main() {
    vector<int> nums = {};
    cout << longestConsecutive(nums);

}