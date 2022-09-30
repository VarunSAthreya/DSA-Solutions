class NumArray
{
    vector<int> fenwick, nums;
    int n;

    void init(int i, int val)
    {
        i++;

        while (i <= n)
        {
            fenwick[i] += val;
            i += (i & -i);
        }
    }

    int getSum(int i)
    {
        int sum = 0;
        i++;
        while (i > 0)
        {
            sum += fenwick[i];
            i -= (i & -i);
        }

        return sum;
    }

public:
    NumArray(vector<int> &nums)
    {
        this->nums = nums;
        n = nums.size();

        fenwick = vector<int>(n + 1, 0);

        for (int i = 0; i < n; i++)
            init(i, nums[i]);
    }

    void update(int index, int val)
    {
        int diff = val - nums[index];
        nums[index] = val;
        init(index, diff);
    }

    int sumRange(int left, int right)
    {
        return getSum(right) - getSum(left - 1);
    }
};
