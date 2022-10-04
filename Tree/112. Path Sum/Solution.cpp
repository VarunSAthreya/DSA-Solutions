class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum, int sum = 0)
    {
        if (!root)
            return false;

        if (targetSum == sum + root->val && !root->right && !root->left)
            return true;

        return hasPathSum(root->left, targetSum, sum + root->val) || hasPathSum(root->right, targetSum, sum + root->val);
    }
};
