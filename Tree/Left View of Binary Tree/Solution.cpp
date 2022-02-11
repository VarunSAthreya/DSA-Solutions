// Function to return a list containing elements of left view of the binary tree.

void travel(vector<int> &res, Node *root, int lvl, int *max_lvl)
{
    if (root == NULL)
        return;

    if (*max_lvl < lvl)
    {
        res.push_back(root->data);
        *max_lvl = lvl;
    }
    travel(res, root->left, lvl + 1, max_lvl);
    travel(res, root->right, lvl + 1, max_lvl);
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    int max_lvl = 0;
    travel(res, root, 1, &max_lvl);
    return res;
}
