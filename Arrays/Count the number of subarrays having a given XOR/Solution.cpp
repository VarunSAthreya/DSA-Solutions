int solve(vector<int> &nums, int target)
{
    map<int, int> mpp;
    int count = 0;
    int XOR = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        XOR = XOR ^ nums[i];
        int y = XOR ^ target;
        if (XOR == target)
            count++;
        else if (mpp.find(y) != mpp.end())
        {
            count += mpp[y];
        }
        mpp[XOR]++;
    }
    return count;
}
