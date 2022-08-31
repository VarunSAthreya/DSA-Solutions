class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        map<string, int> mpp;
        int num = words.size(), n = words[0].size();
        for (string w : words)
        {
            mpp[w]++;
        }
        vector<int> res;
        if (s.size() < n * num)
        {
            return res;
        }

        for (int i = 0; i <= s.size() - n * num; i++)
        {
            map<string, int> dup(mpp);
            for (int j = 0; j < num; j++)
            {

                string st = s.substr(i + j * n, n);
                if (dup.find(st) != dup.end())
                {
                    if (dup[st] == 1)
                    {
                        dup.erase(st);
                    }
                    else
                    {
                        dup[st]--;
                    }
                    if (dup.size() == 0)
                    {
                        res.push_back(i);
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }

        return res;
    }
};
