class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int width = 0;

        if (!root)
            return width;

        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            long long mmin = q.front().second;

            int first, last;

            for (int i = 0; i < size; i++)
            {
                long long cur_id = q.front().second - mmin;
                TreeNode *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur_id;
                if (i == size - 1)
                    last = cur_id;

                if (node->left)
                    q.push({node->left, cur_id * 2 + 1});
                if (node->right)
                    q.push({node->right, cur_id * 2 + 2});
            }
            width = max(width, last - first + 1);
        }

        return width;
    }
};
