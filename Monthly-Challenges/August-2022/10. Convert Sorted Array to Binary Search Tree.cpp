class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return nullptr;

        int m = l + (r - l) / 2;
        TreeNode *node = new TreeNode(nums[m]);

        node->left = helper(nums, l, m - 1);
        node->right = helper(nums, m + 1, r);

        return node;
    }
};
