#include <iostream>
using namespace std;

void bubbleSort(vector<int>& v1) {
    int size = v1.size();
    bool didSwap;
    for (int i = 0; i < size; i++) {
        didSwap = false;
        for (int j = 0; j < (size - 1) - i; j++) {
            if (v1[j] > v1[j+1]) {
                swap(v1[j], v1[j+1]);
                didSwap = true;
            }
        }
        if (!didSwap) {
            cout << "EARLY STOPPED! \nRAN: " << i + 1 << " TIMES" << endl;
            return;
        }
    }
}

int main() {

    vector<int> v1 = {1,2,3,4,5};
    bubbleSort(v1);
    for (auto i: v1) {
        cout << i << " ";
    }
    return 0;
}