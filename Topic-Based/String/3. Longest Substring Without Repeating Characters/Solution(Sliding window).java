class Solution {
    public static int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1)
            return s.length();

        int longest = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        int left = 0;
        for (int right = 0; right < s.length(); right++) {
            char ch = s.charAt(right);
            if (map.containsKey(ch)) {
                left = Math.max(left, map.get(ch) + 1);
            }
            map.put(ch, right);
            longest = Math.max(longest, right - left + 1);
        }
        return longest;
    }
}
