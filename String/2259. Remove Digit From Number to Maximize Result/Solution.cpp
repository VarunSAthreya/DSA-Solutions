class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        string res;
        int last = 0;

        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == digit)
            {
                last = i;
                if (i == number.size() - 1)
                {
                    break;
                }
                if (number[i + 1] - '0' > digit - '0')
                {
                    res += number.substr(i + 1);
                    return res;
                }
            }
            res += number[i];
        }

        if (res.size() == number.size())
        {
            res.erase(last, 1);
        }
        return res;
    }
};
