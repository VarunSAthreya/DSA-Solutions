class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }
        Arrays.sort(intervals, (a, b) -> (a[0] - b[0]));
        int[] last = intervals[0];
        int count = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= last[1]) {
                last = intervals[i];
            } else if (intervals[i][0] < last[1]) {
                count++;
                last[1] = Math.min(last[1], intervals[i][1]);
            }
        }
        return count;
    }
}