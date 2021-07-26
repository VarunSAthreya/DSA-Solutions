// Does not work: Time limit exceeded

class Solution {
    public int numIslands(char[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0)
            return 0;

        int count = 0;

        int[][] directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[0].length; col++) {
                if (grid[row][col] == '1') {
                    count++;
                    Queue<int[]> queue = new LinkedList<>();
                    queue.offer(new int[] { row, col });
                    while (!queue.isEmpty()) {
                        int[] currentDir = queue.poll();
                        int currRow = currentDir[0];
                        int currCol = currentDir[1];
                        grid[currRow][currCol] = '0';
                        for (int[] dir : directions) {
                            int newRow = currRow + dir[0];
                            int newCol = currCol + dir[1];

                            if (newRow >= 0 && newCol >= 0 && newRow < grid.length && newCol < grid[0].length
                                    && grid[newRow][newCol] != '0') {
                                queue.offer(new int[] { newRow, newCol });
                            }

                            // if (newRow < 0 || newCol < 0 || newRow >= grid.length || newCol >=
                            // grid[0].length
                            // || grid[newRow][newCol] == '0') {
                            // continue;
                            // }
                            // queue.offer(new int[] { newRow, newCol });

                        }

                    }
                }
            }
        }
        return count;
    }
}
