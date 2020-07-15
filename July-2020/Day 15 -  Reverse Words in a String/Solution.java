class Solution {
    public String reverseWords(String s) {
        String[] str = s.split(" ");
        StringBuffer sBuff = new StringBuffer();
        for(int i=str.length-1;i>=0;i--){
            if(!str[i].isEmpty()){
              sBuff= sBuff.append(str[i]);
                if(i!=0){
                    sBuff.append(" ");
                }  
            }
 
        }
        return sBuff.toString().trim();
    }
}