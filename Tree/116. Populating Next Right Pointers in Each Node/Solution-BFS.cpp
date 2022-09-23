class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int len = q.size() - 1;

            auto node = q.front();
            q.pop();

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);

            while (len--)
            {
                auto tmp = q.front();
                q.pop();

                node->next = tmp;
                node = tmp;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return root;
    }
};
