// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int ns = s.length();
        int np = p.length();
        int[] sRef = new int[26];
        int[] pRef = new int[26];
        List<Integer> results = new ArrayList<>();
        
        if(ns < np) {
            return results; // No solution
        }
        
        // Build the reference array for p
        for(char ch : p.toCharArray()) {
            pRef[ch - 'a']++;
        }
        
        // Slide window and compare
        for(int i = 0; i < ns; i++) {
            sRef[s.charAt(i) - 'a'] ++; // Add right
            
            if(i >= np) {
                sRef[s.charAt(i - np) - 'a']--; // Remove from left
            }
            
            if(Arrays.equals(sRef, pRef)) {
                results.add((i - np) + 1);
            }
        }
        
        return results;
    }
}
