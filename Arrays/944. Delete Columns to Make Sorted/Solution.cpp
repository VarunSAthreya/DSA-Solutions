// OWN
class Solution
{
public:
    int minDeletionSize(vector<string> &s)
    {
        int cnt = 0;
        for (int i = 0; i < s[0].size(); i++)
        {
            char prev = s[0][i];
            for (int j = 0; j < s.size(); j++)
            {
                if (prev > s[j][i])
                {
                    cnt++;
                    break;
                }
                else
                {
                    prev = s[j][i];
                }
            }
        }

        return cnt;
    }
};

// Leetcode:

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int delete_count = 0;
        int row = strs.size();
        int col = strs[0].size();

        for (int j = 0; j < col; j++)
        {
            for (int i = 0; i < row - 1; i++)
            {
                if (strs[i][j] > strs[i + 1][j])
                {
                    delete_count++;
                    break;
                }
            }
        }
        return delete_count;
    }
};
