#include <iostream>
using namespace std;

vector<int> operation(string& text) {
   
    int size = text.size();
    vector<int> frequencyArray(27, 0);

    for (char i: text) {
        i = tolower(i);
        frequencyArray.at(i-97) += 1;
    }

    return frequencyArray;
}

int main() {
    // vector<int> v = {1,2,2,2,2,1,4,1,2,3};
    
    // int size = v.size();


    // vector<int> hashArray(size, 0);  

    // for (int i = 0; i < size; i++) {
    //     hashArray.at(v.at(i)) += 1;
    // }

    // cout << hashArray.at(3);
    // cout << hashArray.at(2);

    // Character hashing
    string text = "abcddddabc";
    
    vector<int> frequencyArray = operation(text);
    cout << frequencyArray.at('d' - 97);
    return 0;
} 