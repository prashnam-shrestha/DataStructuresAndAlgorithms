#include <iostream>
using namespace std;

string f(string words[], int size) {
    // Map to store frequencey of each string
    unordered_map<string, int> asciiTotal;

    // Pre compute total ascii value
    for (int i = 0; i < size; i++) {
        asciiTotal[words[i]]++;
    }
    // Finding the unique one

    for (auto i: asciiTotal) {
        if (i.second == 1) {
            return i.first;
        }
    }
    return words[0];
}

int main() {

    string words[] = {"abc", "abc", "abc", "xyz"};
    cout << f(words, 4);
    return 0;
}