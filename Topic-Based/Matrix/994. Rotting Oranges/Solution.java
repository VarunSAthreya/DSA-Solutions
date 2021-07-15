import java.util.ArrayList;
import java.util.List;

class Solution {
    public int orangesRotting(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0)
            return -1;

        int fresh = 1;
        int rotten = 2;
        int[][] directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        int freshCount = 0;
        Queue<int[]> queue = new LinkedList<>();
        int count = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == fresh) {
                    freshCount++;
                } else if (grid[i][j] == rotten) {
                    queue.offer(new int[] { i, j });
                }
            }
        }

        int currOrange = queue.size();

        while (!queue.isEmpty()) {
            if (currOrange == 0) {
                count++;
                currOrange = queue.size();
            }

            int[] currentDir = queue.poll();
            currOrange--;

            for (int[] dir : directions) {
                int newRow = currentDir[0] + dir[0];
                int newCol = currentDir[1] + dir[1];

                if (newRow >= 0 && newCol >= 0 && newRow < grid.length && newCol < grid[0].length
                        && grid[newRow][newCol] == fresh) {
                    freshCount--;
                    grid[newRow][newCol] = rotten;
                    queue.offer(new int[] { newRow, newCol });
                }
            }

        }

        return freshCount == 0 ? count : -1;
    }
}
