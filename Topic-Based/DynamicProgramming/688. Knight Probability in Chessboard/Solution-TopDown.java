class Solution {
    private int[][] directions = new int[][] { { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 },
            { -1, 2 }, { -2, 1 } };
    private double[][][] dp;

    public double knightProbability(int N, int K, int r, int c) {
        dp = new double[N][N][K + 1];
        return find(N, K, r, c);
    }

    public double find(int N, int K, int r, int c) {
        if (r < 0 || r > N - 1 || c < 0 || c > N - 1)
            return 0;

        if (K == 0)
            return 1;

        if (dp[r][c][K] != 0)
            return dp[r][c][K];

        double res = 0;
        for (int[] dir : directions) {
            res += find(N, K - 1, r + dir[0], c + dir[1]) / 8;
        }
        dp[r][c][K] = res;
        return res;
    }
}
