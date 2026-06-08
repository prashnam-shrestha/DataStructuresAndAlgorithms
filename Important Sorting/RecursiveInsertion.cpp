
// Online IDE - Code Editor, Compiler, Interpreter

#include<iostream>
#include<vector>

using namespace std;

void recursiveInsertion(vector<int>& v1, int n) {
    if(n == v1.size()) {
        return;
    }
    int right = n;
    int left = right - 1;
    
    
    while(left >= 0) {
        if(v1[right] < v1[left]){
            swap(v1[right], v1[left]);
        }
        else {
            break;
        }
        right--;
        left--;
        
    }
    
    cout << endl;
    recursiveInsertion(v1, n+1);
}


int main()
{
    vector<int> v1 = {86,0,764,7,-9,8,4,99,-7,6};
    recursiveInsertion(v1, 0);
    for(auto i: v1) {
        cout << i << " ";
    }
    return 0;
}
