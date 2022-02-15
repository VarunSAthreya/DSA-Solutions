class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> res;

        if (!root)
            return res;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        map<int, int> mpp;

        while (!q.empty())
        {
            auto pr = q.front();
            q.pop();

            Node *node = pr.first;
            int level = pr.second;
            mpp[level] = node->data;

            if (node->left)
                q.push({node->left, level - 1});
            if (node->right)
                q.push({node->right, level + 1});
        }

        for (auto pr : mpp)
            res.push_back(pr.second);

        return res;
    }
};
