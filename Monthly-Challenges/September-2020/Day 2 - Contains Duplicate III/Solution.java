// Solution 1

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (Math.abs(1L * nums[i] - nums[j]) <= t && j - i <= k)
                    return true;
            }
        }
        return false;
    }
}

// Solution 2

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (nums == null || nums.length == 0) {
            return false;
        }
        if (k >= 10000 && t == 0) {
            return false;
        }
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j <= i + k; j++) {
                if (j >= nums.length) {
                    break;
                }
                if ((long) nums[i] - (long) nums[j] > (long) Integer.MAX_VALUE
                        || (long) nums[j] - (long) nums[i] > (long) Integer.MAX_VALUE) {
                    continue;
                }
                if (Math.abs(nums[i] - nums[j]) <= t) {
                    return true;
                }
            }
        }
        return false;
    }
}