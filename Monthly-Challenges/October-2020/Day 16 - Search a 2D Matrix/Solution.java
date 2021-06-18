class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0)
            return false;
        int m = matrix.length, n = matrix[0].length;
        int r = 0, c = n - 1;
        while (c >= 0 && r < m) {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                c--;
            else
                r++;
        }
        return false;
    }
}