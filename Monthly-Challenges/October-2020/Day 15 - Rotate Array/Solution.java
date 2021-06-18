class Solution {
    public void rotate(int[] nums, int k) {
        k %= nums.length; // if k > length of array
        reverse(nums, 0, nums.length - 1); // reverse full array
        reverse(nums, 0, k - 1); // reverse first k elements
        reverse(nums, k, nums.length - 1); // reverse remaining n - k elements after k
    }

    // For recursion lover one can easily change belwo reverse method in recursive
    // code too.
    private void reverse(int[] nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = temp;
        }
    }
}