class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return !root || helper(root->left, root->right);
    }

    bool helper(TreeNode *left, TreeNode *right)
    {
        if (!right || !left)
        {
            return right == left;
        }
        if (right->val != left->val)
            return false;

        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};
