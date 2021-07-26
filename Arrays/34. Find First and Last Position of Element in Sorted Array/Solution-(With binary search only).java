class Solution {
    public static int[] searchRange(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        int initialPos = binarySearch(nums, target, left, right);

        if (initialPos == -1) {
            return new int[] { -1, -1 };
        } else {
            left = lowerLimit(nums, 0, initialPos - 1, target, initialPos);
            right = upperLimit(nums, initialPos + 1, nums.length - 1, target, initialPos);
            return new int[] { left, right };
        }
    }

    public static int lowerLimit(int[] nums, int left, int right, int target, int previousPos) {
        int currentLeftMostPos = binarySearch(nums, target, left, right);

        if (currentLeftMostPos == -1) {
            return previousPos;
        } else {
            return lowerLimit(nums, left, currentLeftMostPos - 1, target, currentLeftMostPos);
        }
    }

    public static int upperLimit(int[] nums, int left, int right, int target, int previousPos) {
        int currentRightMostPos = binarySearch(nums, target, left, right);

        if (currentRightMostPos == -1) {
            return previousPos;
        } else {
            return upperLimit(nums, currentRightMostPos + 1, right, target, currentRightMostPos);
        }
    }

    public static int binarySearch(int[] nums, int target, int left, int right) {
        int pos = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                pos = mid;
                break;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return pos;
    }
}
