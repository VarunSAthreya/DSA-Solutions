class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mapp(256, -1);

        int n = s.length();
        int left = 0, right = 0;
        int count = 0;

        while (right < n)
        {
            if (mapp[s[right]] != -1)
                left = max(mapp[s[right]] + 1, left);

            mapp[s[right]] = right;
            count = max(count, right - left + 1);
            right++;
        }

        return count;
    }
};

// Slower using unordered map:
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mapp;

        int n = s.length();
        int left = 0, right = 0;
        int count = 0;

        while (right < n)
        {
            if (mapp.find(s[right]) != mapp.end())
                left = max(mapp[s[right]] + 1, left);

            mapp[s[right]] = right;
            count = max(count, right - left + 1);
            right++;
        }

        return count;
    }
};
