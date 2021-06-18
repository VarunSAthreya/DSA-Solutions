class Solution {
    public void moveZeroes(int[] nums) {
        if(nums.length<=1)
            return;
       int i=0,j=0;
        while(j<nums.length) {
        	if(nums[j]==0)
        		j++;
        	else {
        		 nums[i]+=nums[j];
                 nums[j]=nums[i]-nums[j];
                 nums[i]-=nums[j];
        		 i++;
        		 j++;
        	}
        }
    }
}
