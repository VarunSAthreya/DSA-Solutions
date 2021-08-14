class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = 0, c = matrix[0].size() - 1;
        bool flag = false;
        while (r < matrix.size() && r >= 0 && c < matrix[0].size() && c >= 0)
        {
            if (matrix[r][c] == target)
            {
                flag = true;
                break;
            }
            else if (matrix[r][c] > target)
            {
                c--;
            }
            else
            {
                r++;
            }
        }
        return flag;
    }
};
