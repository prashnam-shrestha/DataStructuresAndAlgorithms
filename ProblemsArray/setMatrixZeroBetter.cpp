#include <iostream>
using namespace std;

void setMatrixZero(vector<vector<int>> &matrix) {
    int size = matrix.size();
    int columnSize = matrix[0].size();
    vector<int> rows(size, 0);
    vector<int> column(columnSize, 0);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < columnSize; j++) {
            if (matrix[i][j] == 0) {
                rows[i] = 1;
                column[j] = 1;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < columnSize; j++) {
            if (rows[i] == 1 || column[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
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