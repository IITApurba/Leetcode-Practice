class Solution {
public:
    int solutionCount = 0;
    // Use hash sets for O(1) isSafe check instead of O(n) iteration
    unordered_set<int> cols;           // columns with queens
    unordered_set<int> diag1;          // main diagonals (row - col)
    unordered_set<int> diag2;          // anti-diagonals (row + col)

    // O(1) safety check using hash sets instead of O(n) iteration
    bool isSafe(int row, int col) {
        return cols.find(col) == cols.end() &&
               diag1.find(row - col) == diag1.end() &&
               diag2.find(row + col) == diag2.end();
    }

    // Backtracking function following LCCM framework
    void solveNQueens(int row, int N) {
        // BASE CASE: If all queens are placed
        if (row == N) {
            solutionCount++;
            return;
        }

        // CHOICE: Try placing queen in every column
        for (int col = 0; col < N; col++) {
            // CHECK: Is placing a queen here safe?
            if (isSafe(row, col)) {
                // MOVE: Place the queen
                cols.insert(col);
                diag1.insert(row - col);
                diag2.insert(row + col);

                // Recur to place the next queen
                solveNQueens(row + 1, N);

                // BACKTRACK: Remove the queen and try the next column
                cols.erase(col);
                diag1.erase(row - col);
                diag2.erase(row + col);
            }
        }
    }
    int totalNQueens(int N) {
        cols.clear();
        diag1.clear();
        diag2.clear();
        solutionCount = 0;
        solveNQueens(0, N);
        return solutionCount;
    }
};