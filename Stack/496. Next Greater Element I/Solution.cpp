class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        int n = nums1.size();
        unordered_map<int, int> mapp;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                mapp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = mapp.count(nums1[i]) ? mapp[nums1[i]] : -1;
        }
        return ans;
    }
};

// Editing originl vector nums1 instead of creating new vector

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> st;
        int n = nums1.size();
        unordered_map<int, int> mapp;

        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                mapp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (mapp[nums1[i]] == 0)
            {
                nums1[i] = -1;
                continue;
            }
            nums1[i] = mapp[nums1[i]];
        }
        return nums1;
    }
};
