class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();

        for (int i = 0; i < n; i++)
            if (manager[i] != -1)
                graph[manager[i]].add(i);

        Queue<int[]> q = new LinkedList<>(); // Since it's a tree, we don't need `visited` array

        q.offer(new int[] { headID, 0 });
        int result = 0;

        while (!q.isEmpty()) {
            int[] top = q.poll();
            int managerAtGivenLevel = top[0];
            int cumulativeTime = top[1];

            result = Math.max(cumulativeTime, result);

            for (int subordinates : graph[managerAtGivenLevel])
                q.offer(new int[] { subordinates, cumulativeTime + informTime[managerAtGivenLevel] });
        }

        return result;
    }
}
