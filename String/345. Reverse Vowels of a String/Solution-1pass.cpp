class Solution
{
public:
    bool isVowels(char ch)
    {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string reverseVowels(string s)
    {
        int l = 0, r = s.size() - 1;

        while (l < r)
        {
            while (l < r && !isVowels(s[l]))
                l++;
            while (l < r && !isVowels(s[r]))
                r--;

            swap(s[l], s[r]);
            r--, l++;
        }

        return s;
    }
};
