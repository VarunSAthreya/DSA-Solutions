// Using Dutch national flag algorithm

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
            switch (nums[mid])
            {
            case 0:
                // If element is 0
                swap(nums[mid], nums[low]);
                low++, mid++;
                break;
            case 1:
                // If element is 1
                mid++;
                break;
            case 2:
                // If element is 2
                swap(nums[mid], nums[high]);
                high--;
                break;

            default:
                break;
            }
        }
    }
};
