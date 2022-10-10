class Solution
{
public:
    string breakPalindrome(string s)
    {
        int n = s.size();
        if (n == 1) // cannot convert to a non palindrome
            return "";

        for (int i = 0; i < n / 2; i++) // n/2 as the string is a palindrome first half is same as second half
        {
            if (s[i] != 'a')
            {
                s[i] = 'a'; // lexicographically smallest
                return s;
            }
        }

        s[n - 1] = 'b'; // in the case where the whole string is 'a
        return s;
    }
};
