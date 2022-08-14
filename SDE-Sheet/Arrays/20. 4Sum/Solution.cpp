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

// Many optimizations reduced from 96ms -> 4ms

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> total;
        int n = nums.size();
        if (n < 4)
            return total;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if ((long long int)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if ((long long int)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if ((long long int)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if ((long long int)nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    long long int sum = (long long int)nums[left] + nums[right] + nums[i] + nums[j];
                    if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                    else
                    {
                        total.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do
                        {
                            left++;
                        } while (nums[left] == nums[left - 1] && left < right);
                        do
                        {
                            right--;
                        } while (nums[right] == nums[right + 1] && left < right);
                    }
                }
            }
        }
        return total;
    }
};
