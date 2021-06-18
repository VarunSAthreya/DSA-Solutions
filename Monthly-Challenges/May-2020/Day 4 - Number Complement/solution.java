
class Solution {
    public int findComplement(int num) {
        int cp = num;
        int sum = 0;
        while (num > 0) {
            sum = (sum << 1) + 1;
            num >>= 1;
        }
        return sum - cp;

    }
}
