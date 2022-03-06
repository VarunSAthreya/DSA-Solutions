class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        vector<int> start;
        vector<int> end;
        return dfs(root, 0, 1, start, end);
    }

    int dfs(TreeNode *root, int level, int order, vector<int> &start, vector<int> &end)
    {
        if (!root)
            return 0;

        if (start.size() == level)
        {
            start.push_back(order);
            end.push_back(order);
        }
        else
            end[level] = order;

        int cur = end[level] - start[level] + 1;
        int left = dfs(root->left, level + 1, 2 * order, start, end);
        int right = dfs(root->right, level + 1, 2 * order + 1, start, end);

        return max(cur, max(left, right));
    }
};
