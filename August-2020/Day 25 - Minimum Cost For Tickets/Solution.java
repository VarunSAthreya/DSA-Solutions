class Solution {

    private int[] costs;
    private Integer[] memo;
    private Set<Integer> dayset;

    public int mincostTickets(int[] days, int[] costs) {
        this.costs = costs;
        this.memo = new Integer[366];
        this.dayset = new HashSet<>();

        for (int d : days)
            dayset.add(d);

        return dp(1);
    }

    public int dp(int i) {
        if (i > 365)
            return 0;

        if (memo[i] != null)
            return memo[i];

        int ans;

        if (dayset.contains(i)) {
            ans = Math.min(dp(i + 1) + costs[0], Math.min(dp(i + 7) + costs[1], dp(i + 30) + costs[2]));
        } else {
            ans = dp(i + 1);
        }

        memo[i] = ans;

        return ans;

    }
}