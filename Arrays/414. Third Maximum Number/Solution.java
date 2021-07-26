// 2ms
class Solution {
    public int thirdMax(int[] nums) {
        Integer max1 = null;
        Integer max2 = null;
        Integer max3 = null;
        for (Integer n : nums) {
            if (n.equals(max1) || n.equals(max2) || n.equals(max3))
                continue;
            if (max1 == null || n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            } else if (max2 == null || n > max2) {
                max3 = max2;
                max2 = n;
            } else if (max3 == null || n > max3) {
                max3 = n;
            }
        }
        return max3 == null ? max1 : max3;
    }
}

// 0ms
class Solution {
    public int thirdMax(int[] nums) {
        long a = Long.MIN_VALUE;
        long b = Long.MIN_VALUE;
        long c = Long.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > a) {
                c = b;
                b = a;
                a = nums[i];
            }
            if (nums[i] > b && nums[i] < a) {
                c = b;
                b = nums[i];
            }
            if (nums[i] > c && nums[i] < b) {
                c = nums[i];
            }
        }
        if (c == Long.MIN_VALUE) {
            return (int) a;
        } else {
            return (int) c;
        }
    }
}
