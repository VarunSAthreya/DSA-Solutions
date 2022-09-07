class Solution
{
public:
    string tree2str(TreeNode *root)
    {
        string res = to_string(root->val);

        if (root->left)
        {
            res += '(' + tree2str(root->left) + ')';
        }
        if (root->right)
        {
            if (!root->left)
                res += "()"; // left side not present, but right side present
            res += '(' + tree2str(root->right) + ')';
        }

        return res;
    }
};
