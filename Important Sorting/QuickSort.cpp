
#include <iostream>
using namespace std;
// WHAT IS IT?
// QuickSort picks one element as a pivot, places it in its exact
// correct position by putting everything smaller to its left and
// everything larger to its right, then recursively does the same
// thing to the left and right subarrays until the whole array is sorted.

// HOW TIME COMPLEXITY?
// PART A --
// If there are 8 elements
// We are spiliting it into sub arrays [4 elements ] [4 elements] 
// Then sub of that sub array [2] [2] [2] [2] so on. 
// And that spliting N by half each recursion is (log2 N);

// PART B --
// Partition sort takes O(N)

// Final Time complexity = O(N) * O(log2 N) = O(N * log2 N)

void quickSort(vector<int>& v1, int left, int right) { // O(N log2 N)

    if (left >= right) { // BASE CASE
        return;
    }
    // Partition sort (Crazy billiant algorithm) O(N)
    int pivot = v1[right];
    int leftZone = left - 1;
    for (int i = left; i < right; i++) {
        if (v1[i] <= pivot) {
            leftZone++;
            swap(v1[leftZone], v1[i]);
        }
    }
    swap(v1[right], v1[leftZone+1]);

    // Spiliting it into sub arrays [4] [4] -> [2] [2] [2] [2]..
    quickSort(v1, left, leftZone);
    quickSort(v1, leftZone + 2, right);
}

int main() {

    vector<int> v1 = {3,4,2,5,3,7,5,3,6,4,9,9,5,4,2,6};
    quickSort(v1, 0, v1.size() - 1);
    for (auto i : v1) {
        cout << i << " ";
    }
    return 0;
}