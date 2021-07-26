// 2 pointer method

// Steps:
// 1. Identify pointer with lesser value
// 2. Is the pointer value greater than or equal max on that side? YES: Update max on that side: NO: get trapped water at that pointer and add it to total
// 3. move pointer inwards
// 4. repeat the steps for all pointers

class Solution {
    public int trap(int[] height) {
        int left = 0, right = height.length - 1, maxLeft = 0, maxRight = 0, total = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    total += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    total += maxRight - height[right];
                }
                right--;
            }
        }
        return total;
    }
}
