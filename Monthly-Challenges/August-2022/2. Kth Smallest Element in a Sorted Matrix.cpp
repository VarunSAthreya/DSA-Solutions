class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        priority_queue<int, vector<int>, greater<int>> temp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push(matrix[i][j]);
            }
        }

        int res = 0;
        while (k--)
        {
            res = temp.top();
            temp.pop();
        }

        return res;
    }
};
