class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] timestamp = new int[1001];
        for (int[] t : trips) {
            timestamp[t[1]] += t[0];
            timestamp[t[2]] -= t[0];
        }

        for (int number : timestamp) {
            capacity -= number;
            if (capacity < 0)
                return false;
        }

        return true;
    }
}