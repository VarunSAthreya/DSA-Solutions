// O(26N)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0;
        vector<int> mpp(26, 0);
        int n = s.size();
        int res = 0;

        while (right < n)
        {
            mpp[s[right] - 'A']++;
            int cnt = 0;
            for (int i : mpp)
                cnt = max(cnt, i);
            if (right - left + 1 - cnt <= k)
            {
                res = max(res, right - left + 1);
                right++;
            }
            else
            {
                mpp[s[left] - 'A']--;
                right++;
                left++;
            }
        }

        return res;
    }
};

// Optimized: O(N)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0, right = 0;
        vector<int> mpp(26, 0);
        int n = s.size();
        int res = 0, maxFreq = 0;

        while (right < n)
        {
            mpp[s[right] - 'A']++;
            maxFreq = max(maxFreq, mpp[s[right] - 'A']);
            if (right - left + 1 - maxFreq <= k)
            {
                res = max(res, right - left + 1);
            }
            else
            {
                mpp[s[left] - 'A']--;
                left++;
            }
            right++;
        }

        return res;
    }
};
