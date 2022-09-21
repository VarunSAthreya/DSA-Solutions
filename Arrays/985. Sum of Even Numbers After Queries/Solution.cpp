class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> res;
        int n = nums.size(), m = queries.size();

        int total = 0;
        for (int i : nums)
        {
            if (i % 2 == 0)
                total += i;
        }

        for (int i = 0; i < m; i++)
        {
            auto v = queries[i];
            int tmp = nums[v[1]] + v[0];

            if (nums[v[1]] % 2 == 0)
            {
                if (tmp % 2 == 0)
                {
                    total += tmp - nums[v[1]];
                }
                else
                {
                    total -= nums[v[1]];
                }
            }
            else if (tmp % 2 == 0)
            {
                total += tmp;
            }

            nums[v[1]] = tmp;
            res.push_back(total);
        }

        return res;
    }
};
