#include <iostream>
using namespace std;

int main() {
    // Same as c or java
    int grade;
    cin >> grade;
    string result;

    if (grade >= 80) {
        result = 'A';
    }
    else if (grade >= 60) {
        result = 'B';
    }
    else if (grade >= 50) {
        result = 'C';
    }
    else if (grade >= 45) {
        result = 'D';
    }
    else if (grade >= 25) {
        result = 'E';
    }
    else {
        result = 'F';
    }
    cout << result;
 
    return 0;
}