// Function based comparator:
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

        priority_queue<pair<string, int>, vector<pair<string, int>>, function<bool(pair<string, int> a, pair<string, int> b)>> pq(cmp);

        for (auto pr : mpp)
        {
            pq.push(pr);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> res(k);
        for (int i = 0; i < k; i++)
        {
            res[i] = pq.top().first;
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

// Class based comparator:

class Compare
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
            return a.first < b.first;

        return a.second > b.second;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mpp;
        for (string s : words)
            mpp[s]++;

        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

        for (auto pr : mpp)
        {
            pq.push(pr);
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> res(k);
        for (int i = 0; i < k; i++)
        {
            res[i] = pq.top().first;
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
