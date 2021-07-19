import java.util.Arrays;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        double[] disTo = new double[n];
        Arrays.fill(disTo, Double.POSITIVE_INFINITY);
        disTo[k - 1] = 0;

        for (int i = 1; i < n; i++) {
            for (int[] edge : times) {
                int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
                disTo[v] = Math.min(disTo[v], disTo[u] + w);
            }
        }

        double res = Double.MIN_VALUE;

        for (double i : disTo) {
            res = Math.max(i, res);
        }

        return res == Double.POSITIVE_INFINITY ? -1 : (int) res;
    }
}
