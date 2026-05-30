#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int arr[] = {10, 10, 5, 5};
    unordered_map<int, int> frequency;

    for (auto i: arr) {
        frequency[i]++;
    }
    auto random = frequency.begin();
    pair<int, int> highest = {random->first, random->second};
    pair<int, int> lowest = {random->first,random->second};

    for (auto i: frequency) {
        if (i.second > highest.second || i.second == highest.second && i.first < highest.first) {
            highest = i;
        }
        if (i.second < lowest.second || i.second == lowest.second && i.first < lowest.first) {
            lowest = i;
        }
        cout << i.first << " : " << i.second << endl;
    }

    cout << "Highest: " << highest.first << endl;
    cout << "Lowest: " << lowest.first << endl;

    return 0;
}