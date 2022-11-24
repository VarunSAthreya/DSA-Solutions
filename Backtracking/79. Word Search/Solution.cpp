class Solution
{
public:
    vector<vector<int>> dirs{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                if (dfs(board, i, j, word))
                    return true;

        return false;
    }

    bool dfs(vector<vector<char>> &board, int i, int j, string &word)
    {
        if (!word.size()) return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
            return false;

        char c = board[i][j];
        board[i][j] = '*';

        string s = word.substr(1);
        bool res = false;

        for (auto &dir : dirs)
            res = res || dfs(board, i + dir[0], j + dir[1], s);

        board[i][j] = c; // backtracking
        return res;
    }
};
