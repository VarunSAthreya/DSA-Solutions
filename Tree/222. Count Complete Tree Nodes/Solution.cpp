class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = 1;
        auto temp = root;
        while (temp->left)
        {
            l++;
            temp = temp->left;
        }

        int r = 1;
        temp = root;
        while (temp->right)
        {
            r++;
            temp = temp->right;
        }

        if (r == l)
        {
            return (1 << l) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
