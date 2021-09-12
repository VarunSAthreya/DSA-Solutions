class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> nums, int n)
    {
        stack<long long> st;
        vector<long long> ans(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
};
