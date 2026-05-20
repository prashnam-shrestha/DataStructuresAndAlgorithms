#include <iostream>
#include <list>
#include <map>
#include <set>
using namespace std;

int main() {
    stack<int> stack1; 
    stack1.push(10);
    stack1.push(20); // Treated first
    cout << stack1.top() << endl;

    // QUEUE
    queue<int> queue1;
    queue1.push(10); // Treated first
    queue1.push(20);
    cout << queue1.front() << endl;

    // DEQUE
    deque<int> deque1;
    deque1.push_back(20);
    deque1.push_front(10);
    cout << deque1[0] << endl;

    // LIST
    list<int> list1;
    list1.push_back(20);
    list1.push_front(10);
    // list1[0] INDEXING IS NOT SUPPORTED

    priority_queue<int> pQueue1;
    pQueue1.push(10);
    pQueue1.push(20);
    cout << pQueue1.top();

    // SET

    set<int> st;
    st.insert(1);
    st.insert(9);
    st.insert(0);
    st.insert(2);

    cout << "\n-- SETS--" << endl;
    for (auto i: st) {
        cout << i;
    }

    auto i = st.find(0); // RETURNS ADDRESS
    cout << *i;

    st.erase(3);

    cout << st.count(0);

    // MULTI SET (SORTED)
    // UNORDERED SET (UNIQUE)- O(1)

    // MAPS
    cout << "\n";
    map<int, int> mpp;
    mpp[1] = 2;
    mpp.emplace(3, 1);
    mpp.emplace(2, 3);

    for (auto i: mpp) {
        cout << i.second;
    }

    // MULTI MAP
    // UNORDERED MAP 




}