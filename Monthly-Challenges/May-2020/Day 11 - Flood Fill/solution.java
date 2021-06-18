class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;
        fill(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    void fill(int[][] image, int sr, int sc, int newColor, int oldColor) {
        if (sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length || oldColor != image[sr][sc])
            return;
        image[sr][sc] = newColor;
        fill(image, sr + 1, sc, newColor, oldColor);
        fill(image, sr - 1, sc, newColor, oldColor);
        fill(image, sr, sc + 1, newColor, oldColor);
        fill(image, sr, sc - 1, newColor, oldColor);
    }
}
