class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid.length == 0)
            return 0;
        List<int[]> rotted = new ArrayList();
        int fresh = 0;
        int ans = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 2)
                    rotted.add(new int[] { i, j });
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        if (fresh == 0)
            return 0;
        while (rotted.size() > 0) {
            List<int[]> temp = new ArrayList();
            for (int[] coor : rotted) {
                int i = coor[0], j = coor[1];
                if (i - 1 >= 0 && grid[i - 1][j] == 1) {
                    temp.add(new int[] { i - 1, j });
                    grid[i - 1][j] = 2;
                    fresh--;
                }
                if (i + 1 < grid.length && grid[i + 1][j] == 1) {
                    temp.add(new int[] { i + 1, j });
                    grid[i + 1][j] = 2;
                    fresh--;
                }
                if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                    temp.add(new int[] { i, j - 1 });
                    grid[i][j - 1] = 2;
                    fresh--;
                }
                if (j + 1 < grid[0].length && grid[i][j + 1] == 1) {
                    temp.add(new int[] { i, j + 1 });
                    grid[i][j + 1] = 2;
                    fresh--;
                }
            }
            rotted = temp;
            ans++;
        }
        if (fresh > 0)
            return -1;
        return --ans;
    }
}