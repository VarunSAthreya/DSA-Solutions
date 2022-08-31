class Solution
{
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        vector<bool> visited(target.size(), false);
        vector<int> res;
        int count = 0;

        while (count != target.size())
        {
            bool didChange = false;
            for (int i = 0; i <= target.size() - stamp.size(); i++)
            {
                if (!visited[i] && canReplace(target, i, stamp))
                {
                    count = replace(target, i, stamp.size(), count);
                    visited[i] = true;
                    didChange = true;
                    res.push_back(i);

                    if (target.size() == count)
                        break;
                    cout << count << "\n";
                }
            }

            if (!didChange)
                return vector<int>{0};
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool canReplace(string target, int pos, string stamp)
    {
        for (int i = 0; i < stamp.size(); i++)
        {
            if (target[i + pos] != '?' && target[i + pos] != stamp[i])
            {
                return false;
            }
        }
        return true;
    }

    int replace(string target, int pos, int len, int count)
    {
        for (int i = 0; i < len; i++)
        {
            if (target[i + pos] != '?')
            {
                target[i + pos] = '?';
                count++;
            }
        }
        return count;
    }
};
