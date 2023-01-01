// Own solution: 0ms, 100%
class Solution
{
public:
    bool detectCapitalUse(string s)
    {
        bool flag = true;
        bool cap = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == 1 && s[i] <= 'Z' && s[0] <= 'Z')
                cap = true;
            if (i > 0 && !cap && s[i] <= 'Z')
                return false;

            if (s[i] > 'Z' && cap)
                return false;
        }

        return true;
    }
};

// Leetcode solution: 0ms, 100%
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int count = 0;
        if (word.size() == 1)
            return true;

        for (int i = 0; i < word.size(); i++)
            if (isupper(word[i]))
                count++;

        if (count == 1 && isupper(word[0]))
            return true;
        if (count == 0 || count == word.size())
            return true;
        else
            return false;
    }
};
