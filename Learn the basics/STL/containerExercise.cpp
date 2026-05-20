#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue> 
#include <deque>

using namespace std;

int main() {

    // EXERCISE 1
    set<int> uniqueGuests;
    multiset<int> allScans;

    vector<int> incomingTickets({105, 201, 105, 304, 201, 402});

    for (auto i: incomingTickets) {
        uniqueGuests.emplace(i);
        allScans.emplace(i);
    }

    cout << "--SET UNIQUE GUEST--\n";
    for (auto i: uniqueGuests) {
        cout << i << endl;
    }

    cout << "--MULTISET SCANS--\n";
    for (auto i: allScans) {
        cout << i << "\n";
    }

    cout << allScans.count(105);

    // EXERCISE 2
    cout << "\n EXERCISE TWO \n";
    unordered_map<string, int> voteRegistry;
    voteRegistry["Batman"] += 3;
    voteRegistry["Inception"] += 2;
    voteRegistry["Avatar" ]+= 1;

    for (auto i: voteRegistry) {
        cout << i.first << " got " << i.second << " votes " << endl;
    }

    // EXERCISE 3
    cout << "\n EXERCISE 3 \n";
    priority_queue<pair<int, string>> emergencyRoom;
    emergencyRoom.push({3, "Alex"});
    emergencyRoom.push({10, "Random"});
    emergencyRoom.push({0, "Atrina"});
    emergencyRoom.push({9, "Prashnam"});

    while (!emergencyRoom.empty()) {
        cout << emergencyRoom.top().second << endl;
        emergencyRoom.pop();

    }


    // EXERCISE 4
    cout << "\n EXERCISE 4 \n";
    multimap<int, string> catalog;
    catalog.insert({5, "milk"});
    catalog.insert({5, "Bread"});
    catalog.insert({12, "Eggs"});

    deque<string> premiumItems;
    for (auto i: catalog) {
        if (i.first > 10) {
            premiumItems.push_front(i.second);
        }
        else {
            premiumItems.push_back(i.second);
        }
    }

    return 0;




}