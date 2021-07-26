class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() <= 1)
            return s.length();

        int longest = 0;
        for (int left = 0; left < s.length(); left++) {
            HashMap<Character, Boolean> map = new HashMap<>();
            int currLong = 0;
            for (int right = left; right < s.length(); right++) {
                char ch = s.charAt(right);

                if (!map.containsKey(ch)) {
                    currLong++;
                    map.put(ch, true);
                    longest = Math.max(longest, currLong);
                } else {
                    break;
                }
            }
        }
        return longest;
    }
}
