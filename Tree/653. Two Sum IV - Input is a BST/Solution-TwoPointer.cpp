class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> nums;
        inorder(nums, root);
        int l = 0, r = nums.size() - 1;

        while (l < r)
        {
            if (nums[l] + nums[r] == k)
                return true;
            if (nums[l] + nums[r] > k)
                r--;
            else
                l++;
        }

        return false;
    }

    void inorder(vector<int> &nums, TreeNode *root)
    {
        if (!root)
            return;

        inorder(nums, root->left);
        nums.push_back(root->val);
        inorder(nums, root->right);
    }
};
