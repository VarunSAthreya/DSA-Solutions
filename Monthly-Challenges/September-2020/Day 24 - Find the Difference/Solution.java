class Solution {
    public char findTheDifference(String s, String t) {
        int[] map = new int[26];
        
        for (char c : s.toCharArray()) {
            map[c-'a']++;
        }
        for (char c : t.toCharArray()) {
            map[c-'a']--;
            
            if (map[c-'a'] < 0) {
                return c;
            }
        }
        return 'a';
    }
}