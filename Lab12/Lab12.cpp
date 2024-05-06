#include <iostream>
#include <vector>

using namespace std;


pair<int, int> findMinMaxIndicesSumAndProduct(const vector<vector<int>>& matrix) {
    int minRow = 0, minCol = 0, maxRow = 0, maxCol = 0;


    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] < matrix[minRow][minCol]) {
                minRow = i;
                minCol = j;
            }
            if (matrix[i][j] > matrix[maxRow][maxCol]) {
                maxRow = i;
                maxCol = j;
            }
        }
    }


    return make_pair(minRow + minCol + maxRow + maxCol, minRow * minCol * maxRow * maxCol);
}

int main() {

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };


    pair<int, int> result = findMinMaxIndicesSumAndProduct(matrix);


    cout << "Summa index: " << result.first << endl;
    cout << "Dobutok index: " << result.second << endl;

    return 0;
}
