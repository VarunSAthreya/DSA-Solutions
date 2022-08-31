class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // unordered_map<char,int> m;
        vector<int> m(26, 0);
        for (char ch : magazine)
        {
            m[ch - 'a']++;
        }

        for (char ch : ransomNote)
        {
            if (--m[ch - 'a'] < 0)
                return false;
        }

        return true;
    }
};
