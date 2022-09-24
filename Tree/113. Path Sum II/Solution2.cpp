class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> path;
        if (!root)
            return res;

        dfs(root, targetSum, res, path);
        return res;
    }

    void dfs(TreeNode *node, int target, vector<vector<int>> &res, vector<int> &path)
    {
        if (!node) // if node is null
            return;

        path.push_back(node->val); // add node value to path

        if (!node->left && !node->right && target == node->val) // if its a leaf node and target is met
        {
            res.push_back(path);
        }

        dfs(node->left, target - node->val, res, path);  // left subtree
        dfs(node->right, target - node->val, res, path); // right subtree

        path.pop_back(); // remove node value from path
    }
};
