#include <iostream>
using namespace std;

int missingNum(vector<int>& v1, int n) {
    int xOR = 0;
    for (int i = 0; i < n; i++) {
        xOR = xOR ^ i;
        xOR = xOR ^ v1[i];
    }
    xOR = xOR ^ n;
    return xOR;
}

int main() {
    vector<int> v1 = {0, 1, 2};
    cout << missingNum(v1, 3);
    return 0;
}