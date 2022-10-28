class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;

        for (string s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(s);
        }

        for (auto [k, v] : m)
            res.push_back(v);

        return res;
    }
};
