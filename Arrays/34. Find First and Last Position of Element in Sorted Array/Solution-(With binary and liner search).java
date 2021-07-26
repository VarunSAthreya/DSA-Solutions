class Solution {
    public static int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int initialIndex = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                initialIndex = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (initialIndex == -1) {
            return new int[] { -1, -1 };
        } else {
            left = initialIndex;
            right = initialIndex;
            while (left >= 0 && nums[left] == target)
                left--;
            while (right < nums.length && nums[right] == target)
                right++;
            return new int[] { ++left, --right };
        }
    }
}
