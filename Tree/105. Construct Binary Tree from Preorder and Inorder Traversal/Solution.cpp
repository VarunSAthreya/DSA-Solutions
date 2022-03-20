class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++)
        {
            hash[inorder[i]] = i;
        }
        return helper(preorder, inorder, hash, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, map<int, int> &hash, int pstart, int pend, int istart, int iend)
    {
        if (istart > iend || pstart > pend)
            return NULL;

        TreeNode *root = new TreeNode(preorder[pstart]);
        int ind = hash[preorder[pstart]];
        int rem = ind - istart;

        TreeNode *left = helper(preorder, inorder, hash, pstart + 1, pstart + rem, istart, ind - 1);
        TreeNode *right = helper(preorder, inorder, hash, pstart + rem + 1, pend, ind + 1, iend);
        root->left = left;
        root->right = right;

        return root;
    }
};
