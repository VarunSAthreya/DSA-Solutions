public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        if (n == 0)
            return 0;

        int result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            if ((n & 1) == 1)
                result++;
            n >>= 1;
        }
        return result;
    }
}
// Another Solution

public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int times = 31;
        int ret = 0;

        while (times >= 0) {
            int lastDigit = n & 1;
            if (lastDigit == 1) {
                ret = ret | (lastDigit << times);
            }
            times--;
            n = n >> 1;
        }
        return ret;
    }
}