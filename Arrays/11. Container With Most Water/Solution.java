class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int max = 0;
        int j = height.length - 1;
        while (i < j) {
            int area = Math.min(height[i], height[j]) * (j - i);
            max = Math.max(max, area);
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return max;
    }
}
