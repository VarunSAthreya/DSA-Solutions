class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        if (!root->left && !root->right)
            return 1;

        vector<int> freq(9 + 1, 0);
        int res = 0;
        freq[root->val]++;
        helper(root, freq, res);
        return res;
    }

    bool checkPseudoPalindrome(vector<int> &freq)
    {
        int odd = 0;
        for (auto i : freq)
        {
            if (i % 2 == 1)
                odd++;
        }
        return odd <= 1;
    }

    void helper(TreeNode *root, vector<int> &freq, int &res)
    {
        if (!root->left && !root->right)
        {
            if (checkPseudoPalindrome(freq))
                res++;
            return;
        }

        if (root->left)
        {
            freq[root->left->val]++;
            helper(root->left, freq, res);
            freq[root->left->val]--;
        }
        if (root->right)
        {
            freq[root->right->val]++;
            helper(root->right, freq, res);
            freq[root->right->val]--;
        }
    }
};
