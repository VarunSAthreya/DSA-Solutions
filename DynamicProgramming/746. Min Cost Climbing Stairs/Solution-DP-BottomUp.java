class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;

        int dpOne = cost[0];
        int dpTwo = cost[1];
        for (int i = 2; i < n; i++) {
            int current = cost[i] + Math.min(dpOne, dpTwo);
            dpOne = dpTwo;
            dpTwo = current;
        }
        return Math.min(dpOne, dpTwo);
    }
}
