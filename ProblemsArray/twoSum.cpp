
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

vector<int> twoSum(vector<int>& v1, int target) {
    
    int size = v1.size();
    unordered_map<int, int> freq;
    
    vector<int> nums;
    
    for(int i = 0; i < size; i++) {
        if(freq.find(target - v1[i]) != freq.end()) {
            return {i, freq[target - v1[i]]};
        }
        freq[v1[i]] = i;
    }
    
        cout << endl;
      
    return {-1,-1};
}

int main()
{
    return 0;
}
