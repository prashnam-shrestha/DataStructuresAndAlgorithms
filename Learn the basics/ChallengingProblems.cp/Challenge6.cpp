#include <iostream>
using namespace std;

int main() { // O(log N)

    int n = 212;
    int totalNum = 1;
    bool output = true;
    // Get the total multiply
    while (n > 0) {
        int digit = n % 10;
        if (digit > 0) {
            totalNum = totalNum * digit;
            
        }
        n = n / 10;
    }

    // Check if its palindrome
    string totalString = to_string(totalNum);
    int left = 0;
    int right = totalString.length() - 1;

    while (left < right) {
        if (totalString[left] != totalString[right]) {
            output = false;
            break;
        }
        left++;
        right--;
    }

    cout << output;
    return 0;
}