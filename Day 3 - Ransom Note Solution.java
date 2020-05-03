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
