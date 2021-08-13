class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> vec(numRows);

        for (int i = 0; i < numRows; i++)
        {
            vec[i].resize(i + 1);
            vec[i][0] = vec[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
            }
        }
        return vec;
    }
};

// Same solution different method (faster in execution 3ms -> 0ms)
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

// For finding the value of pascal triangle in a specific index(r,c) then formula: r-1^ C c-1;

// For printing the value of the n row of pascal triangle in O(n)
// Calculating value of:
//  [n * (n-1) * --- * (n-k+1) ]
// code:

for (int i = 0; i < k; i++)
{
    res *= (n - 1);
    res /= (i + 1);
}
