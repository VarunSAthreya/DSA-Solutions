class Solution
{
public:
    static bool cmp(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    }

    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mpp;
        for (string s : words)
            mpp[s]++;

        vector<pair<string, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), cmp);

        vector<string> res(k);
        for (int i = 0; i < k; i++)
            res[i] = v[i].first;

        return res;
    }
};
