
class Solution
{
public:
    vector<int> minPartition(int N)
    {
        int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

        vector<int> res;
        int ind = 9; // number of coins (0-9)

        while (ind >= 0)
        {
            if (coins[ind] <= N)
            {
                res.push_back(coins[ind]);
                N -= coins[ind];
            }
            else
            {
                ind--;
            }
        }

        return res;
    }
};
