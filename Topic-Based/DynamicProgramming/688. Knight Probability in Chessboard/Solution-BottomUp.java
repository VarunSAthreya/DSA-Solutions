class Solution {
    public double knightProbability(int n, int k, int row, int col) {
        double[][][] dp = new double[k + 1][n][n];
        int[][] directions = new int[][] { { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 },
                { -2, 1 } };
        dp[0][row][col] = 1;
        for (int step = 1; step <= k; step++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    for (int[] dir : directions) {
                        int prevRow = r + dir[0];
                        int prevCol = c + dir[1];
                        if (prevRow >= 0 && prevRow < n && prevCol >= 0 && prevCol < n) {
                            dp[step][r][c] += dp[step - 1][prevRow][prevCol] / 8;
                        }
                    }
                }
            }
        }
        double result = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                result += dp[k][r][c];
            }
        }
        return result;
    }
}
