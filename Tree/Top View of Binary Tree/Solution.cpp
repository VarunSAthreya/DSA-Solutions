
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;

        queue<pair<Node *, int>> q;
        map<int, int> mpp;

        q.push({root, 0});

        while (!q.empty())
        {
            auto pr = q.front();
            q.pop();

            Node *node = pr.first;
            int level = pr.second;

            if (mpp.find(level) == mpp.end())
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
