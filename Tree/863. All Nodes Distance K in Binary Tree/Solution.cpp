class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> res;
        if (!root)
            return res;

        map<TreeNode *, TreeNode *> mpp;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();

            if (node->left)
            {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }

        queue<pair<TreeNode *, int>> qu;
        map<TreeNode *, bool> v;

        qu.push({target, 0});
        v[target] = true;

        while (!qu.empty())
        {
            auto pr = qu.front();
            TreeNode *node = pr.first;
            int level = pr.second;
            if (level == k)
                break;

            qu.pop();

            if (node->left && !v[node->left])
            {
                qu.push({node->left, level + 1});
                v[node->left] = true;
            }
            if (node->right && !v[node->right])
            {
                qu.push({node->right, level + 1});
                v[node->right] = true;
            }
            if (mpp.find(node) != mpp.end() && !v[mpp[node]])
            {
                qu.push({mpp[node], level + 1});
                v[mpp[node]] = true;
            }
        }

        while (!qu.empty())
        {
            auto pr = qu.front();
            qu.pop();
            if (pr.second == k)
            {
                res.push_back(pr.first->val);
            }
        }

        return res;
    }
};
