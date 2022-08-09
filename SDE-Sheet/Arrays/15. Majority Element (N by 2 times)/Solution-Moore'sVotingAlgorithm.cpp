class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0;
        int ele = -1;
        // Intuition: count is incremented and decremented based on either if its the same ele or not therefore the majority element will eventually be assigned as ele as its occurrence is > n/2(greater than sum of the occurrance of all the rest of the elements)
        for (auto i : nums)
        {
            if (count == 0)
                ele = i;
            if (ele == i)
                count++;
            else
                count--;
        }

        return ele;
    }
};
