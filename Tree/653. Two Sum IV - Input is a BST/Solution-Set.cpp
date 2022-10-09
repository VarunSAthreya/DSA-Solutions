class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> m;
        return dfs(root, k, m);
    }

    bool dfs(TreeNode *root, int k, unordered_set<int> &m)
    {
        if (!root)
            return false;
        if (m.count(root->val))
            return true;
        m.insert(k - root->val);
        return dfs(root->left, k, m) || dfs(root->right, k, m);
    }
};
