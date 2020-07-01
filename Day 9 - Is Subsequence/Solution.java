class Solution {
    public boolean isSubsequence(String s, String t) {
         if(s.length() == 0)
            return true;
        int i = 0;
        for(char ch : t.toCharArray()){
            if(i > s.length() -1) break;
            char temp = s.charAt(i);
            if(temp == ch){
                i++;
            }
        }
        return i == s.length();
    }
}