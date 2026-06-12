#include <iostream>
using namespace std;

bool isSorted(vector<int> v1) {
    if (v1.size() == 1) {
        return true;
    }
    for (int i = 0; i < v1.size() - 1; i++) {
        if (v1[i] > v1[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> v1 = {5,4,6,7,8};
    cout << isSorted(v1);
    return 0;
}