class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        vector<int> res;
        int n = changed.size();
        if (n % 2 == 1)
            return res;

        multiset<int> s;
        for (auto i : changed)
            s.insert(i);

        while (s.size() > 0)
        {
            auto it = s.begin();
            int first = *it;
            s.erase(it);
            auto it2 = s.find(first * 2);

            if (it2 != s.end())
            {
                s.erase(it2);
                res.push_back(first);
            }
            else
            {
                return {};
            }
        }

        if (s.size() > 0)
            return {};

        return res;
    }
};
