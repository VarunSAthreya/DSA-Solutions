class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vec(numRows);

        for (int i = 0; i < numRows; i++)
        {
            vec[i].push_back(1);
            for (int j = 1; j < i; j++)
            {
                vec[i].push_back(vec[i - 1][j - 1] + vec[i - 1][j]);
            }
            if (i > 0)
            {
                vec[i].push_back(1);
            }
        }

        return vec;
    }
};
