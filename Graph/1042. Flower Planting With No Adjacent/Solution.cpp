class Solution
{
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths)
    {
        unordered_map<int, vector<int>> mpp;
        vector<int> res(n);

        for (auto v : paths)
        {
            mpp[v[0]].push_back(v[1]);
            mpp[v[1]].push_back(v[0]);
        }

        for (int i = 1; i <= n; i++)
        {
            vector<int> colors(5); // 5 as there are 4 colors and to represent (1,4)
            for (auto v : mpp[i])
            {
                colors[res[v - 1]] = 1;
            }

            for (int j = 1; j <= 4; j++) // 4 as there are 4 colors
                if (colors[j] == 0)
                    res[i - 1] = j;
        }

        return res;
    }
};
