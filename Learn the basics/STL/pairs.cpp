#include <iostream>
#include <utility>

using namespace std;

int main() {
    // Simple pair
    pair<int, int> p = {1, 2};
    cout << p.first;
    cout << p.second;

    // Nested pairs
    pair<int, pair<int, int>> b = {1, {2,3}};
    cout << b.first;
    cout << b.second.second;

    // Array of pair

    pair<int, int> apple[] = {{1,2}, {3,4}};

    cout << apple[1].second;

}