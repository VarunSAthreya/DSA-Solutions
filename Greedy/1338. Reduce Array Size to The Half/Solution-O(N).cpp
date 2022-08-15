/*
    - Take the frequency of each element.
    - Create an vector to find the count of each frequency, max frequency can be N.
    - Then go through the count frequency vector from back and remove the elements from the array with highest frequency.
    - If the removed frequency is greater than or equal to half of the array size, then return the number of removals.
*/

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> mpp;
        for (int i : arr)
            mpp[i]++;

        int n = arr.size();
        vector<int> cnt(n + 1);
        for (auto [_, freq] : mpp)
            cnt[freq]++;

        int res = 0, removed = 0, half = n / 2, freq = n;

        while (removed < half)
        {
            while (cnt[freq] == 0)
                freq--;

            removed += freq;
            res++;
            cnt[freq]--;
        }

        return res;
    }
};
