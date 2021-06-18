class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return result;
        }
        int cand1 = nums[0], cand2 = nums[0];
        int count1 = 0, count2 = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1++;
            } else if (count2 == 0) {
                cand2 = num;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (cand1 == num) {
                count1++;
            } else if (cand2 == num) {
                count2++;
            }
        }
        if (count1 > nums.length / 3) {
            result.add(cand1);
        }
        if (count2 > nums.length / 3) {
            result.add(cand2);
        }
        return result;
    }
}