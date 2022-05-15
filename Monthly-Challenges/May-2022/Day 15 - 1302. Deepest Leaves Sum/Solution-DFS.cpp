/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int depth = 1;
        dfs(root, 1, depth);
        int sum = 0;
        findSum(root, 1, depth, sum);

        return sum;
    }

    void dfs(TreeNode *node, int level, int &depth)
    {
        depth = max(depth, level);

        if (node->left)
            dfs(node->left, level + 1, depth);
        if (node->right)
            dfs(node->right, level + 1, depth);
    }

    void findSum(TreeNode *node, int level, int depth, int &sum)
    {
        if (level == depth)
            sum += node->val;

        if (node->left)
            findSum(node->left, level + 1, depth, sum);
        if (node->right)
            findSum(node->right, level + 1, depth, sum);
    }
};
