class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());

        vector<string> v;

        for (int i = 0; i <= 30 && i < n; i++)
        {
            int tmp = pow(2, i);
            string str = to_string(tmp);
            sort(str.begin(), str.end());
            v.push_back(str);
        }

        for (string str : v)
            if (s == str)
                return true;

        return false;
    }
};
