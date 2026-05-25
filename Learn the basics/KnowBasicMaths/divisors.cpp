#include <iostream>
using namespace std;

vector<int> printDivisors(int num) { // O(n)
    vector<int> collector;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            collector.push_back(i);
        }
    }

    return collector;
}

vector<int> printDivisors2(int num) { // O(Root n)
    // Note that: We can find pattern with -
    // the help of square root n; 
    vector<int> collector; 
    int count = 0;
    // int middle = sqrt(num); // We do I * I <= num (Mathematically accurate)

    for (int i = 1; i*i <= num; i++) {
        if (num % i == 0) {
            collector.push_back(i);
            count++;
        }
    }
    for (int i = count - 1; i >= 0; i-- ) {
        
        int divisor = collector.at(i);
        int newD = num/divisor;
        if (divisor != newD) {
        
             collector.push_back(newD);
        }

    }
    
    return collector;
}


int main() {
    vector<int> v1 = printDivisors2(1);
    for (auto i: v1) {
        cout << i << endl;
    }
    return 0;
}