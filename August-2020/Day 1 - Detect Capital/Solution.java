class Solution {
    public boolean detectCapitalUse(String word) {
        int l = 0, u = 0;
        int n = word.length();
        for (char ch : word.toCharArray()) {
            if (Character.isUpperCase(ch))
                u++;
            if (Character.isLowerCase(ch))
                l++;
        }
        if (u == n)
            return true;
        else if (l == n)
            return true;
        else if (Character.isUpperCase(word.charAt(0)) && l + 1 == n)
            return true;
        else
            return false;
    }
}