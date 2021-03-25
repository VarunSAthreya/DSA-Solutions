class Solution {
    public boolean isPerfectSquare(int num) {
        int rem = num % 10;
        if (rem == 2 || rem == 3 || rem == 7 || rem == 8)
            return false;
        int l = 1;
        int r = num;
        while (l <= r) {
            long m = l + (r - l) / 2;
            if ((m * m) == num)
                return true;
            else if ((m * m) > num)
                r = (int) m - 1;
            else
                l = (int) m + 1;
        }
        return false;
    }
}
