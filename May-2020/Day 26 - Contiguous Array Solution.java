// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3341/

/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
    public int findMaxLength(int[] arr) {
        if(arr.length<=1)
            return 0;
        Map <Integer, Integer> map = new HashMap<>();
        int sum = arr[0] == 0 ? -1 : 1;
        int max = 0;
        map.put(0, -1);
        map.put(sum, 0);
        for(int i = 1 ; i < arr.length; i++){
            sum = arr[i] == 0 ? sum -1 : sum + 1;
            if(map.containsKey(sum)){
                max = Math.max(max, i - map.get(sum));
            }
            else
                map.put(sum, i);
        }
        return max;
    }
}
