bool helper(TreeNode *root, int val, vector<int> &res)
{
    if (!root)
        return false;

    res.push_back(root->val);

    if (root->val == val)
        return true;

    if (helper(root->left, val, res) || helper(root->right, val, res))
        return true;

    res.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> res;
    if (!A)
        return res;

    helper(A, B, res);
    return res;
}
