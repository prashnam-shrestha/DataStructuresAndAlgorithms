#include <iostream>
using namespace std;

int main() { // O(nums.length())

    int nums[] = {1, 2, 3, 1, 1, 3};
    int total = 0;
    unordered_map<int, int> frequency;

    for (auto i: nums) {
        frequency[i]++;
    }
    for (auto i: frequency) {
        total += ( i.second * (i.second-1))/2;
    }
    cout << total;
    return 0;
}