#include <iostream>
using namespace std;

vector<int> reverseArr(vector<int> nums) {

    vector<int> reversed;
    int size = nums.size();
    for (int i = size - 1; i >= 0; i--) {
        reversed.push_back(nums.at(i));
    }
    return reversed;
}

vector<int> reverseArrR(vector<int> nums) {
    
    // Base case
    vector<int> ans;
    ans.push_back()
    return ans;


}

int main() {

    vector<int> v = {1,2,3,4};
    vector<int> v1 = reverseArr(v);
    for (auto i: v1) {
        cout << i << endl;
    }
    return 0;
}