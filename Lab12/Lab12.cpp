#include <iostream>

using namespace std;

struct MinMaxIndices {
    int minRow, minCol, maxRow, maxCol;
};

struct SumAndProduct {
    int sumIndex, productIndex;
};

void findMinMaxIndices(const int matrix[][3], int rows, int cols, MinMaxIndices& indices) {
    indices = { 0, 0, 0, 0 };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] < matrix[indices.minRow][indices.minCol]) {
                indices.minRow = i;
                indices.minCol = j;
            }
            if (matrix[i][j] > matrix[indices.maxRow][indices.maxCol]) {
                indices.maxRow = i;
                indices.maxCol = j;
            }
        }
    }
}

void calculateSumAndProductIndices(const MinMaxIndices& indices, SumAndProduct& result) {
    result.sumIndex = indices.minRow + indices.minCol + indices.maxRow + indices.maxCol;
    result.productIndex = indices.minRow * indices.minCol * indices.maxRow * indices.maxCol;
}

int main() {
    const int rows = 3;
    const int cols = 3;

    int matrix[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    MinMaxIndices minMaxIndices;
    SumAndProduct result;

    findMinMaxIndices(matrix, rows, cols, minMaxIndices);
    calculateSumAndProductIndices(minMaxIndices, result);

    cout << "Summa index: " << result.sumIndex << endl;
    cout << "Dobutok index: " << result.productIndex << endl;

    return 0;
}
