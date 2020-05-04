/*
Given an arbitrary ransom note string and another string containing letters from all the magazines,
write a function that will return true if the ransom note can be constructed from the magazines ;
otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> map = new HashMap<>();
        
        for(char ch : magazine.toCharArray()){
            if(map.containsKey(ch)){
                int count = map.get(ch) + 1;
                map.put(ch, count);
            }
            else
                map.put(ch, 1);
        }
        for(char ch : ransomNote.toCharArray()){
            if(!map.containsKey(ch)){
                return false;
            }
            int count = map.get(ch);
            if(count == 0)
                return false;
            map.put(ch, count-1);
        }
        return true;
    }
}
