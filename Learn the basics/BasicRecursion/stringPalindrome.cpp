#include <iostream>
using namespace std;

bool stringPalindrome(string& text, int left, int right) {

    if (left > right) {
        return true;
    }
    if (text.at(left) != text.at(right)) {
        return false;
    }
    return stringPalindrome(text, left + 1, right - 1);

}

int main() {

    string textRaw = "A man, a plan, a canal, Panama!";
    string text = "";
    for (char i: textRaw) {
        if (isalnum(i)) {
            text += tolower(i);
        }
    }
    cout << text << endl;
    cout << stringPalindrome(text, 0, text.length() - 1);
    return 0;
}