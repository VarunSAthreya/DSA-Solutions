class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> prefix(n);
        vector<int> sufix(n);

        int hi = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sufix[i] = max(hi, height[i]);
            hi = sufix[i];
        }

        hi = 0;

        for (int i = 0; i < n; i++)
        {
            prefix[i] = max(hi, height[i]);
            hi = prefix[i];
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += min(sufix[i], prefix[i]) - height[i];
        }

        return ans;
    }
};
