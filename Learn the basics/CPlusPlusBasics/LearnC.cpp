#include<iostream>
using namespace std;

    // Comments
    // int, long, long long, float, double
    // string and getline 
    // char 
    // Array
    // while for loop
    // Function
    // void
    // return
    // parameterised
    // non parameterised
    // array is always sent by reference in function

// pass by value
void doSomething(int num[]) {
    num[0] += 100;
    cout << num[0];
}

int main() {
    int num[2];
    num[0] = 10;
    num[1] = 20;
    
    doSomething(num);
    cout << num[0];
    return 0;
}
