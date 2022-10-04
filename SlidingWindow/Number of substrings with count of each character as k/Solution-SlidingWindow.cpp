bool have_same_frequency(map<char, int> &freq, int k)
{
    for (auto &pair : freq)
    {
        if (pair.second != k && pair.second != 0)
        {
            return false;
        }
    }
    return true;
}

int count_substrings(string s, int k)
{
    int count = 0;
    int distinct = (set<char>(s.begin(), s.end())).size();
    for (int length = 1; length <= distinct; length++)
    {
        int window_length = length * k;
        map<char, int> freq;
        int window_start = 0;
        int window_end = window_start + window_length - 1;
        for (int i = window_start;
             i <= min(window_end, s.length() - 1); i++)
        {
            freq[s[i]]++;
        }
        while (window_end < s.length())
        {
            if (have_same_frequency(freq, k))
            {
                count++;
            }
            freq[s[window_start]]--;
            window_start++;
            window_end++;
            if (window_length < s.length())
            {
                freq[s[window_end]]++;
            }
        }
    }
    return count;
}
