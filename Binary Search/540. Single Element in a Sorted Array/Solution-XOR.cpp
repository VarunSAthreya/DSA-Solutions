class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int XOR = 0;
        for (int i : nums)
        {
            XOR = XOR ^ i;
        }
        return XOR;
    }
};
