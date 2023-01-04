// Solution: 1
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mpp;
        for (int i : tasks)
            mpp[i]++;

        int cnt = 0;
        for (auto [k, v] : mpp)
        {
            if (v == 1)
                return -1;

            cnt += (v + 2) / 3;
        }

        return cnt;
    }
};

// Solution: 2
class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mpp;
        for (int i : tasks)
        {
            mpp[i]++;
        }

        int cnt = 0;
        for (auto [k, v] : mpp)
        {
            if (v == 1)
                return -1;

            if (v % 3 == 0)
                cnt += v / 3;
            else
                cnt += v / 3 + 1;
        }

        return cnt;
    }
};
