// Map
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        unordered_map<int, unordered_set<int>> box;

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '.')
                    continue;

                if (rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || box[(i / 3) * 3 + j / 3].count(board[i][j]))
                    return false;

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                box[(i / 3) * 3 + j / 3].insert(board[i][j]);
            }
        }

        return true;
    }
};

// Array
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int rows[9][9] = {0}, cols[9][9] = {0}, box[9][9] = {0};
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = ((i / 3) * 3) + (j / 3);
                    if (rows[i][num] || cols[j][num] || box[k][num])
                        return false;
                    rows[i][num] = cols[j][num] = box[k][num] = 1;
                }

        return true;
    }
};
