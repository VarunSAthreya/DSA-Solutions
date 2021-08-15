class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;

        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    long long int curr = (long long int)nums[i] + nums[j] + nums[right] + nums[left];
                    if (curr < target)
                    {
                        left++;
                    }
                    else if (curr > target)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int> sum(4);
                        sum[0] = nums[i];
                        sum[1] = nums[j];
                        sum[2] = nums[left];
                        sum[3] = nums[right];

                        res.push_back(sum);

                        while (left < right && sum[2] == nums[left])
                            left++;

                        while (left < right && sum[3] == nums[right])
                            right--;
                    }

                    while (j + 1 < n && nums[j + 1] == nums[j])
                        j++;
                }
                while (i + 1 < n && nums[i + 1] == nums[i])
                    i++;
            }
        }
        return res;
    }
};
