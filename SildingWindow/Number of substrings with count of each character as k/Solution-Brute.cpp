/*
 * The idea is to traverse through all substrings. We fix a starting point, traverse through all substrings starting with the picked point, we keep incrementing frequencies of all characters. If all frequencies become k, we increment the result. If the count of any frequency becomes more than k, we break and change starting point.
 */

int MAX_CHAR = 26;

bool check(int freq[], int k)
{
    for (int i = 0; i < MAX_CHAR; i++)
        if (freq[i] && freq[i] != k)
            return false;
    return true;
}

int substrings(string s, int k)
{
    int res = 0; // Initialize result

    for (int i = 0; s[i]; i++)
    {

        int freq[MAX_CHAR] = {0};

        for (int j = i; s[j]; j++)
        {

            int index = s[j] - 'a';
            freq[index]++;

            if (freq[index] > k)
                break;

            else if (freq[index] == k &&
                     check(freq, k) == true)
                res++;
        }
    }
    return res;
}
