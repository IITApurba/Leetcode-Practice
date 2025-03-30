class Solution {
public:
    vector<vector<string>> solutions; // Stores all valid board configurations

    // Check if it's safe to place a queen at board[row][col]
    bool isSafe(vector<string>& board, int row, int col, int N) {
        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q')
                return false;

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }

    // Backtracking function following LCCM framework
    void solveNQueens(int level, vector<string>& board, int N) {
        // BASE CASE: If all queens are placed
        if (level == N) {
            solutions.push_back(board);
            return;
        }

        // CHOICE: Try placing queen in every column
        for (int col = 0; col < N; col++) {
            // CHECK: Is placing a queen here safe?
            if (isSafe(board, level, col,N)) {
                // MOVE: Place the queen
                board[level][col] = 'Q';

                // Recur to place the next queen
                solveNQueens(level + 1, board,N);

                // BACKTRACK: Remove the queen and try the next column
                board[level][col] = '.';
            }
        }
    }
    int totalNQueens(int N) {

        vector<string> board(N, string(N, '.')); // Initialize board with '.'

        solveNQueens(0, board, N);


        return solutions.size();
    }
};