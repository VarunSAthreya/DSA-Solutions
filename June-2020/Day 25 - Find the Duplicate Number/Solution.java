// 2ms soln
class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        int max_ind = 0;
        int curr_max = 0;
        for (int i = 0; i < n; i++) {
            int id = nums[i] % n;
            nums[id] += n;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > curr_max) {
                curr_max = nums[i];
                max_ind = i;
            }
            nums[i] %= n;
        }
        return max_ind;
    }
}

// 0ms soln
class Solution {
    public int findDuplicate(int[] nums) {
        int rabbit = 0, turtle = 0;
        do {
            rabbit = nums[nums[rabbit]];
            turtle = nums[turtle];
        } while (rabbit != turtle);
        rabbit = 0;
        while (rabbit != turtle) {
            rabbit = nums[rabbit];
            turtle = nums[turtle];
        }
        return turtle;
    }
}