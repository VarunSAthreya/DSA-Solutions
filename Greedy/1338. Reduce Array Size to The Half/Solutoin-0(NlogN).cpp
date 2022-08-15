// Using comparator function to sort. Used if both frequency and the number is required.

class Solution
{
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second > b.second;
    }
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> mpp;

        for (int i : arr)
        {
            mpp[i]++;
        }

        vector<pair<int, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), cmp);

        int cnt = 0;
        int res = 0;
        for (auto pr : v)
        {

            cnt += pr.second;
            res++;
            if (cnt >= arr.size() / 2)
                break;
        }

        return res;
    }
};

// Used only if the frequency is required

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> cnt;
        for (int x : arr)
            ++cnt[x];

        vector<int> frequencies;
        for (auto [_, freq] : cnt)
            frequencies.push_back(freq);
        sort(frequencies.begin(), frequencies.end());

        int ans = 0, removed = 0, half = arr.size() / 2, i = frequencies.size() - 1;
        while (removed < half)
        {
            ans += 1;
            removed += frequencies[i--];
        }
        return ans;
    }
};
