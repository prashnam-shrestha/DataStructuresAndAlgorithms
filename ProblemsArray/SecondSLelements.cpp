
#include <iostream>
using namespace std;

void secondSmallLarge(vector<int>& v1) {
    int size = v1.size();
    if (size < 2) {       
        cout << "Second Smallest :" <<  -1  << endl;
        cout << "Second Largest :" <<  -1  << endl; 
        return;
    }
    int largest = v1[0];
    int secondLargest;

    int smallest = v1[0];
    int secondSmallest;


    for (int i = 1; i < size; i++) {
        if (v1[i] > largest) {
            largest = v1[i];
        }
        if (v1[i] < smallest) {
            smallest = v1[i];
        }
    }
    secondSmallest = largest;
    secondLargest = smallest; 

    for (int i = 0; i < size; i++) {
        if (v1[i] > secondLargest && v1[i] != largest) {
            secondLargest = v1[i];
        }
        if (v1[i] < secondSmallest && v1[i] != smallest) {
            secondSmallest = v1[i];
        }
    }
    if (largest == secondLargest || smallest == secondSmallest) {
        cout << "Second Smallest :" <<  -1  << endl;
        cout << "Second Largest :" <<  -1  << endl; 
        return;
    }

    cout << "Second Largest :" <<  secondLargest << endl; 
    cout << "Second Smallest :" <<  secondSmallest << endl;

}

int main() {
    
    vector<int> v1 = {10, 2};
    secondSmallLarge(v1);
    return 0;
}
