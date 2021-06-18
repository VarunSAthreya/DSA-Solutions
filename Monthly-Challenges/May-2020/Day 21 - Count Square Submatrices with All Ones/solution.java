
class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[] counts = new int[n];
        int topleft = 0;
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int top = (i == 0) ? 0 : counts[j];
                    int left = (j == 0) ? 0 : counts[j - 1];
                    counts[j] = 1 + Math.min(top, Math.min(left, topleft));
                    result += counts[j];

                    topleft = (j == n - 1) ? 0 : top;
                } else
                    counts[j] = 0;
            }

        }
        return result;
    }
}
