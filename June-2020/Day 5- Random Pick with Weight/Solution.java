class Solution {
    int[] w_cumm;
    int sum;

    public Solution(int[] w) {
        sum = 0;
        w_cumm = new int[w.length];
        for (int i = 0; i < w_cumm.length; i++) {
            sum += w[i];
            w_cumm[i] = sum;
        }
    }

    public int pickIndex() {
        int idx = (int) (Math.random() * sum);
        return binarySearch(idx + 1);
    }

    int binarySearch(int val) {
        int l = 0;
        int r = w_cumm.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (w_cumm[mid] < val) {
                l = mid + 1;
            } else
                r = mid;
        }
        return l;
    }
}

/**
 * Your Solution object will be instantiated and called as such: Solution obj =
 * new Solution(w); int param_1 = obj.pickIndex();
 */