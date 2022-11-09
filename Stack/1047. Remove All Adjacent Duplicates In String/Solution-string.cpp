class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res = "";
        for (char &c : s)
        {
            if (res.size() && c == res.back())
                res.pop_back();
            else
                res.push_back(c);
        }
        return res;
    }
};

// Solution 2:
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            res.push_back(s[i]);
            while (res.size() && (res.back() == s[i + 1]))
            {
                res.pop_back();
                i++;
            }
        }

        return res;
    }
};
