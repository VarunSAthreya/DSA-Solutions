import java.util.*;
class Solution {
    public int singleNumber(int[] nums) {
        int n=nums.length-1;
        if(n==0)
            return nums[n];
        Arrays.sort(nums);
        int i;
        if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[n]!=nums[n-1])
            return nums[n];
        for(i=1;i<n-1;i++){
            if(nums[i-1]!=nums[i] && nums[i+1]!=nums[i])
                return nums[i];
        }
        return 0;
    }
}
