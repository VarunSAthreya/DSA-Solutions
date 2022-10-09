class Solution
{
public:
    TreeNode *root = NULL;
    bool findTarget(TreeNode *node, int k)
    {
        if (!root)
            root = node;
        if (!node)
            return false;

        if (search(node, k - node->val))
            return true;

        return findTarget(node->left, k) || findTarget(node->right, k);
    }

    bool search(TreeNode *node, int k)
    {
        auto curr = root;

        while (curr != NULL)
        {
            if (k > curr->val)
                curr = curr->right;
            else if (k < curr->val)
                curr = curr->left;
            else
                return curr != node ? true : false;
        }

        return false;
    }
};
