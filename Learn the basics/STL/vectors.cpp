#include <iostream>
#include <utility>

using namespace std;

int main() {
    
    vector<int> v;

    // add (both same, emplace faster)
    v.push_back(1);
    v.emplace_back(2);

    // vector that contains pair
    vector <pair<int, int>> v2;
    v2.push_back({1,2});
    v2.emplace_back(1,2);


    vector<int> v3(5, 100); // Define size and elements
    vector<int> v4(5); // Define size (adjustable)

    // copy a  vector
    vector<int> v5(v3);

    // Access elements
    cout << v5[0];

    vector<int>::iterator it = v3.begin();
    
    cout << *(it) << " ";
    it++;

    // access last element
    cout << v5.back();

    for (vector<int>::iterator it = v5.begin(); it != v5.end(); it++ ) {
        // cout << *(it) << " ";
    }

    // LOOP IN VECTORS
    for (auto it = v5.begin(); it != v5.end(); it++) {
        cout << *(it) << " ";
    }

    for (auto it: v5) {
        cout << it << " ";
    }
    

    

    


    return 0;
}