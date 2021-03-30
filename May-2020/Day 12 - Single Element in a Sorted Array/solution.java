class Solution {
    public int singleNonDuplicate(int[] nums) {
        if (nums.length == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[nums.length - 1] != nums[nums.length - 2])
            return nums[nums.length - 1];
        int l = 0;
        int r = nums.length;

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (m % 2 == 0) {
                if (nums[m] == nums[m - 1])
                    r = m - 2;
                else if (nums[m] == nums[m + 1])
                    l = m + 2;
                else
                    return nums[m];
            } else {
                if (nums[m] == nums[m + 1])
                    r = m - 1;
                else if (nums[m] == nums[m - 1])
                    l = m + 1;
                else
                    return nums[m];
            }
        }
        return -1;
    }
}
