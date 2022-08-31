
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValid(root, NULL, NULL);
    }

    bool isValid(TreeNode *root, TreeNode *minNode, TreeNode *maxNode)
    {
        if (!root)
            return true;
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};
