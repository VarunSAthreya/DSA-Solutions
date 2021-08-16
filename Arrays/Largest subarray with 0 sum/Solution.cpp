int maxLen(int A[], int n)
{
    unordered_map<int, int> mpp;
    int sum = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            res = i + 1;
        }
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                res = max(res, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return res;
}
