int isSumProperty(Node *root)
{
    if (!root || (!root->left && !root->right))
        return 1;

    int sum = 0;
    if (root->right)
        sum += root->right->data;
    if (root->left)
        sum += root->left->data;

    if (sum != root->data)
        return 0;

    return isSumProperty(root->right) && isSumProperty(root->left);
}
