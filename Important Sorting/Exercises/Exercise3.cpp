#include <iostream>
using namespace std;

vector<int> mergeArrays(vector<int>& A, vector<int>& B) {
    vector<int> C;

    int aIndex = 0;
    int aLimit = A.size();

    int bIndex = 0;
    int bLimit = B.size();

    while(aIndex < aLimit && bIndex < bLimit) {
        if (A[aIndex] <= B[bIndex]) {
            C.push_back(A[aIndex]);
            aIndex++;
        }
        else {
            C.push_back(B[bIndex]);
            bIndex++;
        }
    }
    while (aIndex < aLimit) {
        C.push_back(A[aIndex]);
        aIndex++;
    }

    while (bIndex < bLimit) {
        C.push_back(B[bIndex]);
        bIndex++;
    }
    return C;

}

int main() {
    
    vector<int> A = {2, 5, 5, 8};
    vector<int> B = {1, 5, 9};

    vector<int> C = mergeArrays(A, B);

    for (auto i : C) {
        cout << i <<  " ";
    }
    return 0;
}