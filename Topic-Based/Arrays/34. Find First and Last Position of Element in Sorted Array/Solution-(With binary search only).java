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
            left = lowerLimit(nums, 0, initialIndex - 1, target, initialIndex);
            right = upperLimit(nums, initialIndex + 1, nums.length - 1, target, initialIndex);
            return new int[] { left, right };
        }
    }

    public static int lowerLimit(int[] nums, int left, int right, int target, int previousAns) {
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
            return previousAns;
        } else {
            return lowerLimit(nums, left, initialIndex - 1, target, initialIndex);
        }
    }

    public static int upperLimit(int[] nums, int left, int right, int target, int previousAns) {
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
            return previousAns;
        } else {
            return upperLimit(nums, initialIndex + 1, right, target, initialIndex);
        }
    }
}
