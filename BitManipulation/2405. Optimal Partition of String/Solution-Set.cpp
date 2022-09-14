class Solution
{
public:
    int partitionString(string s)
    {
        int right = 0, count = 0;
        unordered_set<char> mpp;
        while (right < s.size())
        {
            if (mpp.count(s[right]))
            {
                count++;
                mpp.clear();
            }
            mpp.insert(s[right]);
            right++;
        }
        return count + 1;
    }
};
