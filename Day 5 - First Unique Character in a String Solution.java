// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3320/

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
class Solution {
    public int firstUniqChar(String s) {
        Map<Character, Integer> map = new HashMap<>();
        
        for(char ch : s.toCharArray()){
            if(map.containsKey(ch))
                map.put(ch, map.get(ch) + 1);
            else
                map.put(ch, 1);
        }
        for(int i = 0; i<s.length(); i++){
            if(map.get(s.charAt(i))== 1)
                return i;
        }
        return -1;
    }
}
