class Solution {
    public void solve(char[][] board) {
        int R = board.length;
        if (R <= 2)
            return;
        int C = board[0].length;
        if (C <= 2)
            return;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'O' && (i == 0 || i == R - 1 || j == 0 || j == C - 1))
                    dfs(board, i, j);
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
        }

    }

    void dfs(char[][] board, int i, int j) {
        if (i >= 0 && i < board.length && j >= 0 && j < board[0].length && board[i][j] == 'O') {
            board[i][j] = 'A';
            dfs(board, i + 1, j);
            dfs(board, i - 1, j);
            dfs(board, i, j + 1);
            dfs(board, i, j - 1);
        }
    }
}