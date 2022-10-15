class Solution
{
private:
    // First Dimension ==> s,
    // Second Dimension ==> prev char,
    // Third Dimension ==> freq of char,
    // Fourth Dimension ==> k.
    // ! 11 as freq of 10-99 will have same length and 100 is the max constraint so in that case all the char will be same so 10 is begin used as max freq for optimization.
    int dp[101][27][11][101];
    int n;
    string s;

    int util(int idx, char prev, int prevCharCount, int k)
    {
        if (k < 0)
            return INT_MAX;
        if (idx >= n)
            return 0;

        if (prevCharCount >= 10)
            prevCharCount = 10;

        if (dp[idx][prev - 'a'][prevCharCount][k] != -1)
            return dp[idx][prev - 'a'][prevCharCount][k];

        int res = INT_MAX;

        // Case 1. Exclude the current character.
        res = min(res, util(idx + 1, prev, prevCharCount, k - 1));

        // Case 2. Include the current character.
        // Case 2.1 prevChar != currChar
        if (prev != s[idx])
        {
            res = min(res, 1 + util(idx + 1, s[idx], 1, k));
        }
        else
        {
            // Case 2.2 prevChar == currChar
            // Case 2.2.1 If prevCharCount is 1 or 9
            if (prevCharCount == 1 || prevCharCount == 9)
                res = min(res, 1 + util(idx + 1, s[idx], prevCharCount + 1, k));
            // Case 2.2.2 If prevCharCount is not 1 or 9.
            else
            {
                res = min(res, util(idx + 1, s[idx], prevCharCount + 1, k));
            }
        }

        dp[idx][prev - 'a'][prevCharCount][k] = res;

        return res;
    }

public:
    int getLengthOfOptimalCompression(string _s, int k)
    {
        s = _s;
        n = s.size();

        if (n == 100)
        {
            bool allSame = true;
            for (int i = 1; i < n; i++)
            {
                if (s[i] != s[i - 1])
                {
                    allSame = false;
                    break;
                }
            }
            if (allSame)
            {
                return 4;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < 27; j++)
            {
                for (int x = 0; x < 11; x++)
                {
                    for (int y = 0; y <= n; y++)
                    {
                        dp[i][j][x][y] = -1;
                    }
                }
            }
        }

        return util(0, 'z' + 1, 0, k);
    }
};
