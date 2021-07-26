class Solution {
    public double knightProbability(int n, int k, int row, int column) {
        if (row < 0 || row >= n || column < 0 || column >= n)
            return 0;
        if (k == 0)
            return 1;
        int[][] directions = { { -2, -1 }, { -2, 1 }, { -1, 2 }, { 1, 2 }, { 2, 1 }, { 2, -1 }, { 1, -2 }, { -1, -2 } };
        int result = 0;
        for (int[] dir : directions) {
            result += knightProbability(n, k, row + dir[0], column + dir[1]);
        }
        return result;
    }
}
