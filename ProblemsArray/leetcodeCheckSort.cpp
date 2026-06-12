#include <iostream>
using namespace std;

bool check(vector<int> & nums) {
    int size = nums.size();
    if (size <= 1) {
        return true;
    }
    bool sorted = true;
    int index;
    for (int i = 0; i < (size-1); i++) {
        if (nums[i] > nums[i+1]) {
            sorted = false;
            index = i+1;
            break;
        }
    }
    if (sorted) {
        return true;
    }
    int rotatedBy = (size) - index;
    rotate(nums.begin(), nums.begin() + (size - rotatedBy), nums.end());

    for (int i = 0; i < (size-1); i++) {
        if (nums[i] > nums[i+1]) {  
            return false;
        }
    }
    return true;
}

int main() {
    // Test Case 1: Standard Rotated Sorted Array (Expected: true)
    vector<int> v1 = {3, 4, 5, 1, 2};
    cout << "Test 1: " << (check(v1) ? "PASSED (true)" : "FAILED (false)") << endl;

    // Test Case 2: Perfectly Sorted, Zero Rotation (Expected: true)
    vector<int> v2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << (check(v2) ? "PASSED (true)" : "FAILED (false)") << endl;

    // Test Case 3: Absolute Jumbled Mess (Expected: false)
    vector<int> v3 = {2, 1, 4, 3, 6};
    cout << "Test 3: " << (check(v3) ? "FAILED (true)" : "PASSED (false)") << endl;

    // Test Case 4: All Elements Are Identical (Expected: true)
    vector<int> v4 = {7, 7, 7, 7};
    cout << "Test 4: " << (check(v4) ? "PASSED (true)" : "FAILED (false)") << endl;

    // Test Case 5: Multiple Duplicates with a Valid Rotation (Expected: true)
    vector<int> v5 = {1, 1, 1, 2, 1, 1};
    cout << "Test 5: " << (check(v5) ? "PASSED (true)" : "FAILED (false)") << endl;

    // Test Case 6: Single-Element Array (Expected: true)
    vector<int> v6 = {10};
    cout << "Test 6: " << (check(v6) ? "PASSED (true)" : "FAILED (false)") << endl;

    return 0;
}