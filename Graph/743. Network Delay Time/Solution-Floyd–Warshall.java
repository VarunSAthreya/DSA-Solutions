import java.util.Arrays;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        double[][] disTo = new double[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(disTo[i], Double.POSITIVE_INFINITY);
        }

        for (int i = 0; i < n; i++) {
            disTo[i][i] = 0;
        }

        for (int[] edge : times) {
            disTo[edge[0] - 1][edge[1] - 1] = edge[2];
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (disTo[i][j] > disTo[i][k] + disTo[k][j])
                        disTo[i][j] = disTo[i][k] + disTo[k][j];
                }
            }
        }

        double max = Double.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            if (disTo[k - 1][i] == Double.POSITIVE_INFINITY)
                return -1;
            max = Math.max(max, disTo[k - 1][i]);
        }

        return (int) max;
    }
}
