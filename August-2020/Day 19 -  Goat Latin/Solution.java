class Solution {
    public String toGoatLatin(String S) {
        StringBuilder sb = new StringBuilder();
        String[] words = S.split(" ");
        String x = "";
        for(String word: words) {
            char f = word.charAt(0);
            char first = Character.toLowerCase(f);
            x = x+"a";
            if(first=='a' || first=='e' ||first=='i' ||first=='o' ||first=='u') {
                sb.append(word); 
            }else {
                sb.append(word.substring(1)); sb.append(f);
            }
            sb.append("ma"+x+" ");         
        }
        
        return sb.toString().trim();
    }
}