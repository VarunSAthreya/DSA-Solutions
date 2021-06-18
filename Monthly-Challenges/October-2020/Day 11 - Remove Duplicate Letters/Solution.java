class Solution {
    public String removeDuplicateLetters(String s) {
        StringBuilder sb = new StringBuilder();
        int[] count = new int[26];
        boolean[] used = new boolean[26];
        char[] chs = s.toCharArray();
        for (char ch : chs) {
            count[ch - 'a']++;
        }
        for (char c : chs) {
            count[c - 'a']--;
            if (used[c - 'a']) {
                continue;
            }
            while (sb.length() > 0 && sb.charAt(sb.length() - 1) > c && count[sb.charAt(sb.length() - 1) - 'a'] > 0) {
                used[sb.charAt(sb.length() - 1) - 'a'] = false;
                sb.deleteCharAt(sb.length() - 1);
            }
            sb.append(c);
            used[c - 'a'] = true;
        }
        return sb.toString();
    }
}