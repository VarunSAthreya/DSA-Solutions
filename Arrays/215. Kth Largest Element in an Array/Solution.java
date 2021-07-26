class Solution {
    public int findKthLargest(int[] nums, int k) {

        // Start iterative method.
        return quickSelect(nums, k);

        // Start recursive method.
        // int indexToFind = nums.length - k;
        // return quickSelect(nums, 0, nums.length - 1, indexToFind);
    }

    // Iterative method
    public int quickSelect(int[] nums, int k) {
        int start = 0;
        int end = nums.length - 1;
        int target = nums.length - k;

        while (true) {
            int partitionIndex = partition(nums, start, end);

            if (partitionIndex < target)
                start = partitionIndex + 1;
            else if (partitionIndex > target)
                end = partitionIndex - 1;
            else
                return nums[partitionIndex];
        }
    }

    // Recursive method
    public int quickSelect(int[] nums, int left, int right, int indexToFind) {

        int partitionIndex = partition(nums, left, right);

        if (partitionIndex == indexToFind) {
            return nums[partitionIndex];
        } else if (indexToFind < partitionIndex) {
            return quickSelect(nums, left, partitionIndex - 1, indexToFind);
        } else {
            return quickSelect(nums, partitionIndex + 1, right, indexToFind);
        }
    }

    public int partition(int[] nums, int start, int end) {
        int pivot = nums[(start + end) / 2];

        while (start < end) {
            while (nums[start] < pivot)
                start++;
            while (nums[end] > pivot)
                end--;

            if (nums[start] > nums[end]) {
                swap(nums, start, end);
            } else
                start++;
        }
        return end;
    }

    public void swap(int[] nums, int start, int end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
}
