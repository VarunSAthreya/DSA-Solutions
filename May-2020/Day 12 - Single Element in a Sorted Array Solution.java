//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3327/

/*
You are given a sorted array consisting of only integers where every element appears exactly twice,
except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
*/

class Solution {
    public int singleNonDuplicate(int[] nums) {
        if(nums.length == 1)
            return nums[0];
        if(nums[0] != nums[1])
            return nums[0];
        if(nums[nums.length-1] != nums[nums.length-2])
            return nums[nums.length-1];
        int l = 0;
        int r = nums.length;
        
        while(l<=r){
            int m = l + (r-l)/2;
            if(m %2 ==0){
                if(nums[m] == nums[m-1])
                    r = m-2;
                else if (nums[m] == nums[m+1])
                    l = m+2;
                else
                    return nums[m];
            }
            else{
                if(nums[m] == nums[m+1])
                    r = m-1;
                else if(nums[m] == nums[m-1])
                    l = m+1;
                else
                    return nums[m];
            }
        }
        return -1;
    }
}
