/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> nodeStack;
        vector<int> res;

        if (root == NULL)
            return res;

        nodeStack.push(root);
        while (!nodeStack.empty())
        {
            TreeNode *node = nodeStack.top();
            res.push_back(node->val);

            nodeStack.pop();

            if (node->left)
                nodeStack.push(node->left);

            if (node->right)
                nodeStack.push(node->right);
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
