class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> result;
        vector<int> vec;
        combinations(1, n, k, vec, result);
        return result;
    }

    void combinations(int start, int n, int k, vector<int> &list, vector<vector<int>> &result)
    {
        if (n == 0 && list.size() == k)
        {
            result.push_back(list);
            return;
        }
        for (int i = start; i <= 9; i++)
        {
            list.push_back(i);
            combinations(i + 1, n - i, k, list, result);
            list.pop_back();
        }
    }
};
