#include <bits/stdc++.h>

class Solution
{
public:
    struct TrieNode
    {
        bool is_end;

        string word;

        TrieNode *child[26];

        TrieNode()
        {
            is_end = false;
            word = ""; // for storing the word, better for efficiency as no need to pass a string to the function

            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    TrieNode *root = new TrieNode();

    void insert(string &str)
    {
        int n = str.size();

        TrieNode *curr = root;

        for (int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';

            if (curr->child[idx] == NULL)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->is_end = true;

        curr->word = str;
    }

    vector<string> res;

    vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    void dfs(vector<vector<char>> &board, int i, int j, int n, int m, TrieNode *curr)
    {

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '#')
            return;

        int idx = board[i][j] - 'a';

        if (curr->child[idx] == NULL)
            return;

        curr = curr->child[idx];

        if (curr->is_end)
        {
            res.push_back(curr->word);
            curr->is_end = false;
        }

        char val = board[i][j];

        board[i][j] = '#';

        for (int k = 0; k < 4; k++)
            dfs(board, i + dir[k][0], j + dir[k][1], n, m, curr);

        board[i][j] = val;
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int n = board.size(), m = board[0].size();

        for (auto word : words)
            insert(word);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dfs(board, i, j, n, m, root);
            }
        }

        return res;
    }
};
