import java.util.Arrays;

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;

        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);

        return Math.min(minCost(n - 1, cost, dp), minCost(n - 2, cost, dp));
    }

    private int minCost(int i, int[] cost, int[] dp) {
        if (i < 0)
            return 0;

        if (i == 0 || i == 1)
            return cost[i];

        if (dp[i] != Integer.MAX_VALUE)
            return dp[i];

        dp[i] = cost[i] + Math.min(minCost(i - 1, cost, dp), minCost(i - 2, cost, dp));
        return dp[i];
    }
}
