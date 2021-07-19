import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<int[]>[] graph = new List[n + 1];
        for (int i = 1; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int[] e : times) {
            graph[e[0]].add(e);
        }

        int[] dists = new int[n + 1];
        Arrays.fill(dists, Integer.MAX_VALUE);
        dists[k] = 0;

        boolean[] visited = new boolean[n + 1];

        Queue<int[]> qQueue = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        qQueue.add(new int[] { k, 0 });

        int left = n, max = 0;

        while (!qQueue.isEmpty() && left > 0) {
            int[] cur = qQueue.poll();

            if (visited[cur[0]])
                continue;

            visited[cur[0]] = true;
            left--;
            max = Math.max(max, cur[1]);

            for (int[] next : graph[cur[0]]) {
                int d = cur[1] + next[2];
                if (d < dists[next[1]]) {
                    dists[next[1]] = d;
                    qQueue.add(new int[] { next[1], d });
                }
            }
        }

        return left == 0 ? max : -1;
    }
}
