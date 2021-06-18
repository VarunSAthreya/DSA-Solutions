class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int max_so_far = Integer.MIN_VALUE;
        int curr_max = 0;
        int min_so_far = Integer.MAX_VALUE;
        int curr_min = 0;
        int sum = 0;

        for (int i : nums) {
            curr_max = Math.max(i, curr_max + i);
            max_so_far = Math.max(max_so_far, curr_max);
            curr_min = Math.min(i, curr_min + i);
            min_so_far = Math.min(min_so_far, curr_min);
            sum += i;
        }

        if (max_so_far > 0)
            return Math.max(max_so_far, sum - min_so_far);
        return max_so_far;
    }

}
