class Solution {
    public int findMaxLeft(int index, int[] height) {
        int max = 0;
        for (int i = index - 1; i >= 0; i--)
            max = Math.max(max, height[i]);
        return max;
    }

    public int findMaxRight(int index, int[] height) {
        int max = 0;
        for (int i = index + 1; i < height.length; i++)
            max = Math.max(max, height[i]);
        return max;
    }

    public int trap(int[] height) {
        int total = 0;
        for (int i = 0; i < height.length; i++) {
            int maxL = findMaxLeft(i, height);
            int maxR = findMaxRight(i, height);
            total += Math.max(Math.min(maxL, maxR) - height[i], 0);
        }
        return total;
    }
}
