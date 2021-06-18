class Solution {
    public int bitwiseComplement(int N) {
        if (N == 0)
            return 1;
        int result = 0, factor = 1;
        while (N > 0) {
            result += factor * (N % 2 == 0 ? 1 : 0);
            N /= 2;
            factor *= 2;
        }
        return result;
    }
}