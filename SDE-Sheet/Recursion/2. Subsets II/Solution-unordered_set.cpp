class Solution
{
private:
    struct hashFunction
    {
        size_t operator()(const vector<int>
                              &myVector) const
        {
            std::hash<int> hasher;
            size_t answer = 0;

            for (int i : myVector)
            {
                answer ^= hasher(i) + 0x9e3779b9 +
                          (answer << 6) + (answer >> 2);
            }
            return answer;
        }
    };

    void helper(vector<int> &nums, int n, unordered_set<vector<int>, hashFunction> &st, vector<int> sub, int ind)
    {
        if (ind == n)
        {
            st.insert(sub);
            return;
        }

        sub.push_back(nums[ind]);
        helper(nums, n, st, sub, ind + 1);
        sub.pop_back();
        helper(nums, n, st, sub, ind + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        unordered_set<vector<int>, hashFunction> st;
        int n = nums.size();
        vector<int> sub;
        helper(nums, n, st, sub, 0);

        vector<vector<int>> res;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            res.push_back(*it);
        }

        return res;
    }
};
