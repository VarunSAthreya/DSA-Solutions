class Solution {
    public String removeKdigits(String num, int k) {
        if (k == num.length())
            return "0";
        int i = 0;
        while (k > 0) {
            i = (i > 0) ? (i - 1) : 0;
            while (i < num.length() - 1 && num.charAt(i) <= num.charAt(i + 1)) {
                i++;
            }
            num = num.substring(0, i) + num.substring(i + 1);
            k--;
        }
        for (i = 0; i < num.length(); i++) {
            if (num.charAt(i) != '0')
                return num.substring(i, num.length());
        }
        return "0";
    }

}
