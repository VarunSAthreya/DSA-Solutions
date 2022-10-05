class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        auto dummy = new TreeNode(0);
        dummy->left = root; // for case: depth = 1

        dfs(dummy, val, depth);
        return dummy->left;
    }

    void dfs(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *node1 = new TreeNode(val), *node2 = new TreeNode(val);
            TreeNode *left = root->left, *right = root->right;

            root->left = node1, root->right = node2;
            node1->left = left, node2->right = right;

            return;
        }

        if (root->left)
            dfs(root->left, val, depth - 1);
        if (root->right)
            dfs(root->right, val, depth - 1);
    }
};
