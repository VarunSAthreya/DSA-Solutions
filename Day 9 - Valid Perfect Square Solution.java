// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3324/

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

class Solution {
    public boolean isPerfectSquare(int num) {
        int rem = num%10;
        if(rem == 2 || rem == 3 || rem == 7 || rem == 8)
            return false; 
        int l = 1;
        int r = num;
        while(l<=r){
            long m = l +(r-l)/2;
            if((m*m) == num)
                return true;
            else if((m*m) >num)
                r =(int) m-1;
            else
                l =(int) m+1;
        }
        return false;
    }
}
