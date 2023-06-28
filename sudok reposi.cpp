  #include <iostream>
using namespace std;

#define N 9

void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, int col, int digit) {
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == digit || grid[i][col] == digit) {
            return false;
        }
    }

    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[boxRow + i][boxCol + j] == digit) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;

    bool isUnassigned = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isUnassigned = true;
                break;
            }
        }
        if (isUnassigned) {
            break;
        }
    }

    if (!isUnassigned) {
        return true;
    }

    for (int digit = 1; digit <= 9; digit++) {
        if (isSafe(grid, row, col, digit)) {
            grid[row][col] = digit;

            cout << "Intermediate step:\n";
            printGrid(grid);
            cout << endl;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int grid[N][N];

    cout << "Enter the Sudoku grid (0 for empty cells):\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }

    cout << "Initial grid:\n";
    printGrid(grid);
    cout << endl;

    if (solveSudoku(grid)) {
        cout << "Sudoku puzzle solved:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle.\n";
    }

    return 0;
}
