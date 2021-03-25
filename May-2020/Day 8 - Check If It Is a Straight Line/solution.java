
class Solution {
    public boolean checkStraightLine(int[][] cord) {
        float m = getSlope(cord[0], cord[1]);
        for (int i = 2; i < cord.length; i++) {
            float slope = getSlope(cord[i], cord[0]);
            if (slope != m)
                return false;
        }
        return true;
    }

    float getSlope(int[] p1, int[] p2) {
        if (p1[0] == p2[0])
            return Float.MAX_VALUE;
        return (float) (p2[1] - p1[1]) / (p2[0] - p1[0]);
    }
}
