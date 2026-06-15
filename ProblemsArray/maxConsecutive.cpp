#include <iostream>
using namespace std;

int maxCon(vector<int> &v1) {
    int max = 0;
    int current = 0;
    int size = v1.size();
 
    for (int i = 0; i < size; i++) {
        
        if (v1[i] == 1) {
            current++;
        }
        if (v1[i] == 0 || i == size - 1) {
            
            if (current > max) {
                max = current; 
            }
            current = 0;
        }
    }
    return max;

}

int main() {
    vector<int> v1 = {1, 1, 1, 0, 1, 0, 1, 1, 1};
    cout << maxCon(v1);
    return 0;
}