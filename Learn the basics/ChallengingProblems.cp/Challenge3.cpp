#include <iostream>
using namespace std;

int main() {
    // O(Size of S)

    string s = "loveleetcode";
    int size = s.length();
    unordered_map<int, int> frequency;

    int output = -1;

    for (auto i : s) {
        frequency[i]++;
    }

    for (int i = 0; i < size; i++) {
        if (frequency[s.at(i)] == 1) {
            output = i;
            break;
        }
    }

    cout << output;

    return 0;

}