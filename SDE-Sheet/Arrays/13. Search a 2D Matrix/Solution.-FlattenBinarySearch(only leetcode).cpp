class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size(), c = matrix[0].size();

        int left = 0, right = (r * c) - 1;
        while (left <= right)
        {
            int mid = (left + (right - left) / 2);
            int mid1 = mid / c;
            int mid2 = mid % c;
            if (matrix[mid1][mid2] == target)
            {
                return true;
            }
            else if (matrix[mid1][mid2] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};
