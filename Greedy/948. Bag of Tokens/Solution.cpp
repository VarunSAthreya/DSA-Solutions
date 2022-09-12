class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());

        int res = 0, cnt = 0;
        int l = 0, r = tokens.size() - 1;
        while (l <= r)
        {
            if (power >= tokens[l])
            {
                power -= tokens[l];
                cnt++;
                l++;
                res = max(res, cnt);
            }
            else if (cnt > 0 && power < tokens[r])
            {
                power += tokens[r];
                cnt--;
                r--;
            }
            else
                break;
        }

        return res;
    }
};
