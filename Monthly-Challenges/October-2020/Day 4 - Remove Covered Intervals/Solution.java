class Solution {
    public int removeCoveredIntervals(int[][] intervals) {

        Arrays.sort(intervals, (a, b) -> (a[0] - b[0]));
        int count = 0, currMin = intervals[0][0], currMax = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][1] <= currMax)
                count++;
            else if (intervals[i][1] > currMax && intervals[i][0] == currMin) {
                count++;
                currMax = intervals[i][1];
            } else {
                currMin = intervals[i][0];
                currMax = intervals[i][1];
            }

        }
        return intervals.length - count;
    }
}