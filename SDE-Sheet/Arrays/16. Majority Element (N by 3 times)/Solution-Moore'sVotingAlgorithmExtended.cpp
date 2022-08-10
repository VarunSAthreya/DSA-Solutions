class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int ele1 = -1, ele2 = -1, cnt1 = 0, cnt2 = 0;

        for (int i : nums)
        {
            if (i == ele1)
                cnt1++;
            else if (i == ele2)
                cnt2++;

            else if (cnt1 == 0)
                ele1 = i, cnt1 = 1;
            else if (cnt2 == 0)
                ele2 = i, cnt2 = 1;
            else
                cnt1--, cnt2--;
        }

        cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        for (int i : nums)
        {
            if (i == ele1)
                cnt1++;
            else if (i == ele2)
                cnt2++;
        }

        vector<int> res;

        if (cnt1 > n / 3)
            res.push_back(ele1);
        if (cnt2 > n / 3)
            res.push_back(ele2);

        return res;
    }
};
