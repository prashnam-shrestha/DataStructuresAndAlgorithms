#include <iostream>
#include <list>
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



}