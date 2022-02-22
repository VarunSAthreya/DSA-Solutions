class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (!root)
            return res;
        vector<int> temp;
        traverse(root, res, temp);

        return res;
    }

    void traverse(TreeNode *root, vector<string> &res, vector<int> &temp)
    {
        if (!root->right && !root->left)
        {
            temp.push_back(root->val);
            res.push_back(path(temp));
            temp.pop_back();
            return;
        }

        temp.push_back(root->val);

        if (root->left)
            traverse(root->left, res, temp);
        if (root->right)
            traverse(root->right, res, temp);
        temp.pop_back();
    }

    string path(vector<int> temp)
    {
        string ans = to_string(temp[0]);
        for (int i = 1; i < temp.size(); i++)
        {
            ans += string("->") + to_string(temp[i]);
        }

        return ans;
    }
};
