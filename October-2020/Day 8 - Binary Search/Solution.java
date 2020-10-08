class Solution {
    public int search(int[] nums, int target) {
        // base cases
        if (nums == null || nums.length == 0)
            return -1;

        return solution(nums, 0, nums.length - 1, target);
    }

    public int solution(int[] nums, int left, int right, int target) {
        // . exit condition
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                return solution(nums, mid + 1, right, target);
            } else {
                return solution(nums, left, mid - 1, target);
            }
        }
        return -1;
    }
}