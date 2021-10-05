// O(2n)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            dp[i][i] = true; // single char is always palindrome

        string ans = s[0];

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                // To check wheather the current chars are same and then check if the inner sequence is palindrome or not
                dp[i][j] = s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]);

                // find the max palindrome
                if (dp[i][j])
                {
                    if (ans.size() < j - i + 1)
                        ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};

// O(n)

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
            return "";
        string ans = "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                dp[i][j] = s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1]);

                if (dp[i][j] && j - i + 1 > ans.size())
                {
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};
