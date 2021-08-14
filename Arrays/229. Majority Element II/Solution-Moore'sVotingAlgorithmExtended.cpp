class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int ele1 = -1, ele2 = -1;
        int count1 = 0, count2 = 0;
        for (int i : nums)
        {
            if (ele1 = i)
            {
                count1++;
            }
            else if (ele2 == i)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                ele1 = i;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                ele2 = i;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        // To verify the count > n /3
        for (int i : nums)
        {
            if (i == ele1)
            {
                count1++;
            }
            else if (i == ele2)
            {
                count2++;
            }
        }

        vector<int> vec;

        if (count1 > nums.size() / 3)
            vec.push_back(ele1);
        if (count2 > nums.size() / 3)
            vec.push_back(ele2);

        return vec;
    }
};
