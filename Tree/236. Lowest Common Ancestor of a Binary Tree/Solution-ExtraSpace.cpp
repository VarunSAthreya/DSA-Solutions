class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return root;

        vector<TreeNode *> path1;
        vector<TreeNode *> path2;

        findPath(root, p, path1);
        findPath(root, q, path2);

        TreeNode *res = root;

        for (int i = 0; i < min(path1.size(), path2.size()); i++)
        {
            if (path1[i] == path2[i])
            {
                res = path1[i];
            }
            else
            {
                break;
            }
        }

        return res;
    }

    bool findPath(TreeNode *root, TreeNode *p, vector<TreeNode *> &path)
    {
        if (!root)
            return false;

        if (root == p)
        {
            path.push_back(root);
            return true;
        }
        path.push_back(root);

        if (findPath(root->left, p, path) ||
            findPath(root->right, p, path))
        {
            return true;
        }

        path.pop_back();
        return false;
    }
};
