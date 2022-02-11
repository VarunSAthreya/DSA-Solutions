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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        queue<vector<int>> q;
        traversal(q, root, 0, 0);

        map<int, map<int, multiset<int>>> mpp;

        // mapping according to vertical and level
        while (!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            mpp[tmp[1]][tmp[2]].insert(tmp[0]);
        }

        vector<vector<int>> res;

        // group according to vertical
        for (auto pr : mpp)
        {
            vector<int> col;
            for (auto q : pr.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }

        return res;
    }

    void traversal(queue<vector<int>> &q, TreeNode *root, int vertical, int level)
    {
        if (!root)
            return;

        vector<int> tmp;
        // Structure: [val, vertical, level]
        tmp.push_back(root->val);
        tmp.push_back(vertical);
        tmp.push_back(level);

        q.push(tmp);

        traversal(q, root->left, vertical - 1, level + 1);
        traversal(q, root->right, vertical + 1, level + 1);
    }
};

// Cleaner Solution

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode *, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty())
        {
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node->val);
            if (node->left)
            {
                todo.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
