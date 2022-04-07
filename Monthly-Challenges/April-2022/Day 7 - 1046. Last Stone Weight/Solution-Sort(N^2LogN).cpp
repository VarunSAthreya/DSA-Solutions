class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        for (int i = stones.size() - 1; i > 0; i--)
        {
            sort(stones.begin(), stones.end());

            if (stones[i] == stones[i - 1])
            {
                stones.pop_back();
                stones.pop_back();
                i--;
            }
            else
            {
                stones[i - 1] = abs(stones[i] - stones[i - 1]);
                stones.pop_back();
            }
        }
        if (stones.size() > 0)
        {
            return stones[0];
        }
        else
        {
            return 0;
        }
    }
};

// Cleaner Solution:

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        int n = stones.size(), ans, count = 0;

        if (n == 1)
            return stones[0];

        while (count != n - 1)
        {
            sort(stones.begin(), stones.end());
            stones[n - 1] = stones[n - 1] - stones[n - 2];
            stones[n - 2] = 0;
            count++;
        }
        return stones[n - 1];
    }
};
