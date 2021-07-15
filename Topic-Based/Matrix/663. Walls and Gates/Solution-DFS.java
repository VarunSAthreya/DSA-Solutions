public class Solution {
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    public void wallsAndGates(int[][] rooms) {
        // write your code here
        if (rooms == null || rooms.length == 0 || rooms[0].length == 0)
            return;

        int gate = 0;

        for (int i = 0; i < rooms.length; i++) {
            for (int j = 0; j < rooms[0].length; j++) {
                if (rooms[i][j] == gate) {
                    dfs(rooms, i, j, 0);
                }
            }
        }

    }

    private void dfs(int[][] rooms, int row, int col, int distance) {
        int inf = 2147483647;

        if (!isBound(rooms, row, col) || rooms[row][col] == -1) {
            return;
        }
        if (rooms[row][col] > distance || distance == 0) {
            rooms[row][col] = distance;
            dfs(rooms, row - 1, col, distance + 1);
            dfs(rooms, row, col + 1, distance + 1);
            dfs(rooms, row + 1, col, distance + 1);
            dfs(rooms, row, col - 1, distance + 1);
        }

    }

    private boolean isBound(int[][] rooms, int row, int col) {
        return row >= 0 && col >= 0 && row < rooms.length && col < rooms[0].length;
    }
}
