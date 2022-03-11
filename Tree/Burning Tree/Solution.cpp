int minTime(Node *root, int target)
{
    if (!root)
        return 0;

    map<Node *, Node *> parent;
    queue<Node *> pq;
    pq.push(root);

    Node *start;
    while (!pq.empty())
    {
        Node *node = pq.front();
        pq.pop();

        if (node->data == target)
            start = node;

        if (node->right)
        {
            parent[node->right] = node;
            pq.push(node->right);
        }
        if (node->left)
        {
            parent[node->left] = node;
            pq.push(node->left);
        }
    }

    queue<pair<Node *, int>> q;
    map<Node *, bool> v;
    q.push({start, 0});
    v[start] = true;
    int res = 0;

    while (!q.empty())
    {
        auto pr = q.front();
        q.pop();

        Node *node = pr.first;
        int level = pr.second;

        res = max(res, level);

        if (node->left && !v[node->left])
        {
            q.push({node->left, level + 1});
            v[node->left] = true;
        }
        if (node->right && !v[node->right])
        {
            q.push({node->right, level + 1});
            v[node->right] = true;
        }
        if (parent.find(node) != parent.end() && !v[parent[node]])
        {
            q.push({parent[node], level + 1});
            v[parent[node]] = true;
        }
    }

    return res;
}
