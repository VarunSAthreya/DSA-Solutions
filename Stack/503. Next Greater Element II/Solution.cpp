// From back -> Front

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i % n])
            {
                st.pop();
            }
            if (i < n)
            {
                if (!st.empty())
                    res[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return res;
    }
};

// From Front -> Back

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> stack, res(n, -1);
        for (int i = 0; i < n * 2; ++i)
        {
            while (stack.size() && nums[stack.back()] < nums[i % n])
            {
                res[stack.back()] = nums[i % n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return res;
    }
};
