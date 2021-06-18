class Solution {
    public int longestPalindrome(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray())
            map.put(c, map.getOrDefault(c, 0) + 1);

        boolean isOddOccurence = false;
        int longestPalindrome = 0;
        for (Integer val : map.values()) {
            longestPalindrome += (val / 2) * 2;
            if (val % 2 == 1)
                isOddOccurence = true;
        }

        return isOddOccurence ? longestPalindrome + 1 : longestPalindrome;
    }
}