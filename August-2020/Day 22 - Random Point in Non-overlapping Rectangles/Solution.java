class Solution {

    Map<Integer, int[]> map;
    int[] cumSum;

    public Solution(int[][] rects) {
        cumSum = new int[rects.length];
        map = new HashMap<>();
        cumSum[0] = (rects[0][2] - rects[0][0] + 1) * (rects[0][3] - rects[0][1] + 1);
        map.put(cumSum[0], rects[0]);
        for (int i = 1; i < rects.length; i++) {
            cumSum[i] = cumSum[i - 1] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
            map.put(cumSum[i], rects[i]);
        }
    }

    public int[] pick() {
        int index = (int) (Math.random() * cumSum[cumSum.length - 1]);
        int low = 0;
        int high = cumSum.length - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            if (cumSum[mid] <= index) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        int[] res = map.get(cumSum[low]);
        int w = res[2] - res[0] + 1;
        int h = res[3] - res[1] + 1;
        int b = cumSum[low] - w * h;
        int x = res[0] + (index - b) % w;
        int y = res[1] + (index - b) / w;
        return new int[] { x, y };
    }
}

// Random weighted pick first. Then call that to get rectangle, then generate
// point in the rectangle

/**
 * Your Solution object will be instantiated and called as such: Solution obj =
 * new Solution(rects); int[] param_1 = obj.pick();
 */