#include <iostream>
using namespace std;

int maxLen(vector<int> &nums) {
    int longest = 0;
    int sum = 0;
    unordered_map<int, pair<int,int>> freqAndIndex;

    int size = nums.size();

    for (int i = 0; i < size; i++) {
        sum += nums[i];
        if (sum == 0) {
            longest = max(i+1, longest);
            continue;
        }
        else if (freqAndIndex[sum].first >= 1) {
            longest = max(i - freqAndIndex[sum].second, longest);
            
        }
        else {
            freqAndIndex[sum].second = i;
        }
        freqAndIndex[sum].first++;

    }
    return longest;
}

int main() {
// --- ULTIMATE CASE 1: The Zero Sandbox ---
// A massive sequence of entirely zeros. 
// Every single subarray sums to 0. It should return the full length.
vector<int> u1 = {0, 0, 0, 0, 0, 0, 0};
cout << "Ultimate Case 1 - Expected: 7, Got: " << maxLen(u1) << endl;

// --- ULTIMATE CASE 2: The Ping-Pong Mirror ---
// Large values that cancel out over massive gaps, with smaller zero-chunks inside.
// Full array: 100 + (-5) + 5 + (-100) = 0 (Len 4)
vector<int> u2 = {100, -5, 5, -100};
cout << "Ultimate Case 2 - Expected: 4, Got: " << maxLen(u2) << endl;

// --- ULTIMATE CASE 3: Only Negative/Positive Segments ---
// An array where no combination can ever equal zero.
vector<int> u3 = {-1, -2, -3, 1, 2};
cout << "Ultimate Case 3 - Expected: 0, Got: " << maxLen(u3) << endl;

// --- ULTIMATE CASE 4: The Anchor Element ---
// A single zero sitting at the very front of an un-cancelable array.
// The longest zero-sum subarray is just the first element {0}.
vector<int> u4 = {0, 5, 7, -2, 4};
cout << "Ultimate Case 4 - Expected: 1, Got: " << maxLen(u4) << endl;

// --- ULTIMATE CASE 5: The Hidden Deep Trap ---
// The running sum drops deep into negative territory and climbs out much later.
// {-20, 10, 5, 5} sums to 0 at the very end (Len 4).
vector<int> u5 = {15, -20, 10, 5, 5};
cout << "Ultimate Case 5 - Expected: 4, Got: " << maxLen(u5) << endl;

    return 0;
}