class Solution
{
public:
    string countAndSay(int n)
    {
        string res = "1";                           // base case for n = 1
        while (--n)
        {
            string cur = "";                        // the next sequence
            for (int i = 0; i < res.size(); i++)    // iterate the previous sequence
            {
                int count = 1;                      // count the number of same digits
                while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
                {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];   // append the count and digit
            }
            res = cur;                              // update the result
        }
        return res;
    }
};
