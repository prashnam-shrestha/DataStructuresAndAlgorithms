
#include <iostream>
using namespace std;

vector<int> unionTwoArray(vector<int> &v1, vector<int> &v2) {
    int num = INT_MIN;
    int sizeV1 = v1.size();
    int sizeV2 = v2.size();

    vector<int> union1;

    int i = 0;
    int j = 0;
    while (i < sizeV1 && j < sizeV2) {
        if (v1[i] < v2[j]) {
            if (v1[i] > num) {
                union1.push_back(v1[i]);
                num = v1[i];
            }
            i++;
        }
        else if (v2[j] < v1[i]) {
            if (v2[j] > num) {
                union1.push_back(v2[j]);
                num = v2[j];
            }
            j++;
        }
        else if (v2[j] == v1[i]) {
            if (v2[j] > num) {
                union1.push_back(v2[j]);
                num = v2[j];
            }
            i++;
            j++;
        }
    }
    while (i < sizeV1) {
        if (v1[i] > num) {
            union1.push_back(v1[i]);
            num = v1[i];
            
        }
        i++;
    }
    while (j < sizeV2) {
        if (v2[j] > num) {
            union1.push_back(v2[j]);
            num = v2[j];
            
        }
        j++;
    }

    return union1;
}
 
int main() {
    vector<int> v1 = {1, 1};
    vector<int> v2 = {1};
    vector<int> union1 = unionTwoArray(v1,v2);

    for(auto i: union1) {
        cout << i << " ";
    }

    return 0;
}