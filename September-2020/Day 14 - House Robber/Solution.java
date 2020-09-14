class Solution {
    public int rob(int[] nums) {
        int dp1 = 0, dp2 = 0, max_amount = 0;
        for(int num: nums) {
            max_amount = Math.max(dp2, num + dp1);
            dp1 = dp2;
            dp2 = max_amount;
        }
        return max_amount;
    }
}