#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first > p2.first) { return true; }
    if (p1.first < p2.first) { return false; }
    if (p1.second < p2.second) { return true; }
    return false;
}

int main() {

    vector<int> v = {1,2,5,3,9,1,4,5};
    sort(v.begin(), v.end());

    sort(v.begin(), v.end(), greater<int>()); // sort in decending order

    int smallest = *min_element(v.begin(), v.end());
    int largest = *max_element(v.begin(), v.end());

    cout << largest;
    cout << smallest << endl;

    // Sorting paris with comparators
    vector<pair<int, int>> v2;
    v2.push_back({100, 9});
    v2.push_back({90, 2});
    v2.push_back({90, 3});
    v2.push_back({50, 5});
    v2.push_back({10, 8});
    v2.push_back({99, 7});
    v2.push_back({95, 1});
    v2.push_back({99, 4});
    v2.push_back({10, 6});

    sort(v2.begin(), v2.end(), comp);

    for (auto i: v2) {
        cout << "Grade: " << i.first << " Roll: " << i.second << endl;
    }

    // builtin pocount = count how many 1 binary num has?
    int num = 9;
    int count = __builtin_popcount(num);
    cout << count << endl;

    string s = "abc";
    sort(s.begin(), s.end());
    
    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));


    return 0;
}