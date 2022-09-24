class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> path;
        if (!root)
            return res;

        // Add root value to path
        path.push_back(root->val);
        dfs(root, targetSum, res, path, root->val);

        return res;
    }

    void dfs(TreeNode *node, int target, vector<vector<int>> &res, vector<int> &path, int sum)
    {
        // check if its a leaf node
        if (!node->left && !node->right)
        {
            if (sum == target) // if target is met
            {
                res.push_back(path);
            }
            return;
        }

        if (node->left)
        {
            int val = node->left->val;
            path.push_back(val); // add left node value to path
            dfs(node->left, target, res, path, sum + val);
            path.pop_back(); // remove left node value from path
        }

        if (node->right)
        {
            int val = node->right->val;
            path.push_back(val); // add right node value to path
            dfs(node->right, target, res, path, sum + val);
            path.pop_back(); // remove right node value from path
        }
    }
};
