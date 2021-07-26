import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

// 8ms - Sorting Array method
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < strs.length; i++) {
            char[] strArray = strs[i].toCharArray();
            Arrays.sort(strArray);
            String key = Arrays.toString(strArray);
            List<String> temp = map.getOrDefault(key, new ArrayList<>());
            temp.add(strs[i]);
            map.put(key, temp);
        }

        return new ArrayList<>(map.values());
    }
}

// 5ms - Using separate char array
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            char[] frequencyArr = new char[26];
            for (int i = 0; i < s.length(); i++) {
                frequencyArr[s.charAt(i) - 'a']++;
            }
            String key = new String(frequencyArr);
            List<String> tempList = map.getOrDefault(key, new ArrayList<String>());
            tempList.add(s);
            map.put(key, tempList);
        }
        return new ArrayList<>(map.values());
    }
}
