class Solution
{
public:
    void convert(vector<vector<int>> &image, int sr, int sc, int color, int newColor, vector<vector<int>> &directions)
    {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != color)
            return;

        image[sr][sc] = newColor;

        for (auto dir : directions)
        {
            convert(image, sr + dir[0], sc + dir[1], color, newColor, directions);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int color = image[sr][sc];
        if (color == newColor)
            return image;
        convert(image, sr, sc, color, newColor, directions);

        return image;
    }
};
