class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;
            while (n--)
            {
                auto node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto i : node->children)
                    q.push(i);
            }

            res.push_back(level);
        }

        return res;
    }
};
