// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.
Each character in S is a type of stone you have.
You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
*/

class Solution {
    public int numJewelsInStones(String J, String S) {
        int count = 0;
        Set<Character> jewels = new HashSet<>();
        for(char ch : J.toCharArray()){
            jewels.add(ch);
        }
        for(char ch : S.toCharArray()){
            if(jewels.contains(ch))
                count++;
        }
        return count;
    }
}
