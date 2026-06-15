// [10, 5, 3, 7, 1, 9]
#include <iostream>
using namespace std;

int longestSubarray(vector<int> &nums, int k) {
    int size = nums.size();
    if (size == 1) {
        if (nums[0] == k) {
            return 1;
        }
        else {return 0;};
    }

    int left = 0;
    int right = 0;
    int longest = 0;
    int sum = nums[left];
    
    while (right < size) {
        if (sum == k) {

            longest = max(right - left + 1, longest);

            sum -= nums[left];
            left++;
            if (++right < size) {
                sum += nums[right];
            }

        }
        else if (sum < k) {
            if (++right < size) {
                sum += nums[right];
            }
        }
        else {
            sum -= nums[left];
            left++;
            
        }
    }
    return longest;

}

int main() {
    
    vector<int> v3 = {1, 2, 1, 1, 1}; 
    int k3 = 4;
    cout << longestSubarray(v3, k3) << endl;
    return 0;
}