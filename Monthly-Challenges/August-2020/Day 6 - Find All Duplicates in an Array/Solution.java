class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int ele = Math.abs(nums[i]);
            if (nums[ele - 1] < 0) {
                result.add(Math.abs(ele));
            }
            nums[ele - 1] = -nums[ele - 1];
        }
        return result;
    }
}