#include <iostream>
#include <vector>

using namespace std;

void squareElements(vector<int>& nums) {
    for (auto &i: nums) {
        i = i*i;
    }
}

void reverseVector(vector<int>& nums) {

    if (nums.empty()) {
        return;
    }
    int* left = &nums[0];
    int* right = &nums[nums.size() - 1];

    while (left < right) {
        swap(*left, *right);

        left+=1;
        right-=1;
    }
}

int main() {

    // Exercise 1
    vector<int> v1;
    for (int i = 1; i <= 10; i++) {
        v1.push_back(i);
    }

    v1.erase(v1.end() - 3, v1.end());

    cout << v1.size() << "\n";

    for (auto num: v1) {
        cout << num;
    }

    // Exercise 2
    vector<int> v2 = {2, 4, 6, 8, 10};
    squareElements(v2);

    // Original values being changed
    for (auto i: v2) {
        cout << i;
    }

    // Exercise 3
    vector<int> v3 = {10, 20, 30, 40, 50};
    
    for (auto i: v3) {
        cout << i << " ";
    }
    cout << "\n";

    reverseVector(v3);

    for (auto i: v3) {
        cout << i << " ";
    }

    // Exercise 4
    vector<int> grades = {1, 2, 2, 5, 4, 1, 2, 0, 5};
    vector<int> freq(6, 0);

    for (auto i: grades) {

        freq[i]++;
    }

    for (auto i: freq) {
        cout << i;
    }
    


    return 0;
}