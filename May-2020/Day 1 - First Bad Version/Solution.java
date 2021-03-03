public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if (n <= 1)
            return n;
        int l = 0;
        int r = n;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
}
