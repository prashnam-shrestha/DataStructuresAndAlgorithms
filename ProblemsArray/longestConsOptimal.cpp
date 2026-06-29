#include <iostream>
#include <unordered_map>
using namespace std;

int longestConsecutive(vector<int> &nums) {

    int max = 1;
    int current = 1;
    unordered_map<int, int> existence;

    for (auto i: nums) {
        existence[i] ++;
    }
    for (auto i: nums) {

        int num = i;
        if (existence.find(num - 1) != existence.end()) {
            continue;
        }
        while (existence.find(num + 1) != existence.end()) {
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
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums);

}