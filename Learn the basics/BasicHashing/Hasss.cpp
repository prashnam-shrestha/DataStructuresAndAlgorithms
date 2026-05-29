#include <iostream>
using namespace std;

int main() {

    vector<int> v = {1,2,2,2,2,1,4,1,2,3};
    int size = v.size();


    vector<int> hashArray(size, 0);

    for (int i = 0; i < size; i++) {
        hashArray.at(v.at(i)) += 1;
    }

    cout << hashArray.at(3);
    cout << hashArray.at(2);
    return 0;
}