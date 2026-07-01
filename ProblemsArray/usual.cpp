#include <iostream>
using namespace std;

void setMatrixZero(vector<vector<int>> &matrix) {
    int size = matrix.size();
    int columnSize = matrix[0].size();
    vector<pair<int,int>> index;
    bool found = false;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < columnSize; j++) {
            if (matrix[i][j] == 0) {
                pair<int,int> temp = {i,j};
                index.push_back(temp);
                found = true;
            }
        }
    }

    if (!found) {
        return;
    }
    for (auto k : index) {

        for (int i = 0; i < size; i++) {

            for (int j = 0; j < columnSize; j++) {
                if (i == k.first) {
                    matrix[i][j] = 0;
                }
                else if(j == k.second) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

}

int main() {

    vector<vector<int>> matrix = {{0,1,1},{1,0,1},{1,1,1}};
    setMatrixZero(matrix);
    int size = matrix.size();
    int columnSize = matrix[0].size();

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < columnSize; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }


}