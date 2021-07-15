import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    public void wallsAndGates(int[][] rooms) {
        // write your code here
        if (rooms == null || rooms.length == 0 || rooms[0].length == 0)
            return;

        int[][] directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        int inf = 2147483647;
        int gate = 0;

        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < rooms.length; i++) {
            for (int j = 0; j < rooms[0].length; j++) {
                if (rooms[i][j] == gate) {
                    queue.offer(new int[] { i, j });
                }
            }
        }
        int level = 1;
        int currentSize = queue.size();

        while (!queue.isEmpty()) {
            if (currentSize == 0) {
                level++;
                currentSize = queue.size();
            }

            int[] currDir = queue.poll();
            currentSize--;

            for (int[] dir : directions) {
                int newRow = currDir[0] + dir[0];
                int newCol = currDir[1] + dir[1];

                if (newRow >= 0 && newCol >= 0 && newRow < rooms.length && newCol < rooms[0].length
                        && rooms[newRow][newCol] == inf) {
                    rooms[newRow][newCol] = level;
                    queue.offer(new int[] { newRow, newCol });
                }
            }
        }

    }
}
