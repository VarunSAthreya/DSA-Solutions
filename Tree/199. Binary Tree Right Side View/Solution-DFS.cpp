// DFS
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;

        traverse(root, res, 0);
        return res;
    }

    void traverse(TreeNode *root, vector<int> &res, int level)
    {
        if (!root)
            return;

        if (res.size() == level)
            res.push_back(root->val);

        traverse(root->left, res, level + 1);
        traverse(root->right, res, level + 1);
        // For left side view, we need to traverse right first
        // traverse(root->right, res, level+1);
        // traverse(root->left, res, level+1);
    }
};
