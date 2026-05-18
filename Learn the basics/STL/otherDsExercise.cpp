#include <iostream>
#include <utility>

using namespace std;

int main() {
    // 1
    string x = "Hello";
    stack<char> st;
    for (char ch: x) {
        st.push(ch);
    }

    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }

    // 2
    queue<string> line;
    line.push("Atrina");
    line.push("Prashnam");
    line.push("Alex");

    cout << line.front() << endl;
    line.pop();
    cout << line.front() << endl;

    // 3
    deque<char> dq;
    string word = "rrdarr";

    for (char ch: word) {
        dq.push_back(ch);
    }


    bool palindrome = true;
    while (dq.size() > 1) {
        if (dq.front() == dq.back()) {
            dq.pop_front();
            dq.pop_back();
        }
        else {
            cout << "Word is not palindrome" << endl;
            palindrome = false;
            break;
        }
    }
    if (palindrome) {
        cout << "Word is palindrome" << endl;
    }

    // 4
    priority_queue<int> pq;
    pq.push(15);
    pq.push(0);
    pq.push(90);
    pq.push(50);
    pq.push(8);
    pq.push(30);

    while (!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }
    

}