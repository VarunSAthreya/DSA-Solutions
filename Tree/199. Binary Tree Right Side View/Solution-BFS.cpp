class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        map<int, TreeNode *> mpp;
        while (!q.empty())
        {
            auto pr = q.front();
            q.pop();
            TreeNode *node = pr.first;
            int level = pr.second;

            mpp[level] = node;
            if (node->left)
                q.push({node->left, level + 1});
            if (node->right)
                q.push({node->right, level + 1});
            // To get the left side view, we need to traverse right first
            // if (node->right)
            //     q.push({node->right, level + 1});
            // if (node->left)
            //     q.push({node->left, level + 1});
        }

        for (auto pr : mpp)
            res.push_back(pr.second->val);

        return res;
    }
};
