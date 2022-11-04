class Solution
{
public:
    bool isVowels(char ch)
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s)
    {
        string v = "";
        for (char ch : s)
        {
            if (isVowels(tolower(ch)))
                v += ch;
        }

        reverse(v.begin(), v.end());

        int ind = 0;
        for (int i = 0; i < s.size() && ind < v.size(); i++)
        {
            char ch = s[i];
            if (isVowels(tolower(ch)))
            {
                s[i] = v[ind++];
            }
        }

        return s;
    }
};
