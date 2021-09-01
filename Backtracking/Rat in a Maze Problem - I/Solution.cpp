// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        string s = "";
        vector<string> ans;
        if (m[0][0] == 0)
        {
            return ans;
        }
        vector<vector<int>> visited(m.size(), vector<int>(m[0].size(), 0));
        visited[0][0] = 1;

        solve(m, n, s, ans, visited, 0, 0);
        return ans;
    }

    void solve(vector<vector<int>> &m, int n, string s, vector<string> &ans, vector<vector<int>> &visited, int row, int col)
    {

        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(s);
            return;
        }

        // Down
        if (row + 1 < n && m[row + 1][col] == 1 && visited[row + 1][col] != 1)
        {
            s += 'D';
            visited[row + 1][col] = 1;
            solve(m, n, s, ans, visited, row + 1, col);
            // Can also be written as
            // solve(m, n, s + 'D', ans, visited, row + 1, col);
            s.pop_back();
            visited[row + 1][col] = 0;
        }

        // Left
        if (col - 1 >= 0 && m[row][col - 1] == 1 && visited[row][col - 1] != 1)
        {
            s += 'L';
            visited[row][col - 1] = 1;
            solve(m, n, s, ans, visited, row, col - 1);
            // Can also be written as
            // solve(m, n, s + 'L', ans, visited, row + 1, col);
            s.pop_back();
            visited[row][col - 1] = 0;
        }

        // Right
        if (col + 1 < n && m[row][col + 1] == 1 && visited[row][col + 1] != 1)
        {
            s += 'R';
            visited[row][col + 1] = 1;
            solve(m, n, s, ans, visited, row, col + 1);
            // Can also be written as
            // solve(m, n, s + 'R', ans, visited, row + 1, col);
            s.pop_back();
            visited[row][col + 1] = 0;
        }

        // Up
        if (row - 1 >= 0 && m[row - 1][col] == 1 && visited[row - 1][col] != 1)
        {
            s += 'U';
            visited[row - 1][col] = 1;
            solve(m, n, s, ans, visited, row - 1, col);
            // Can also be written as
            // solve(m, n, s + 'U', ans, visited, row + 1, col);
            s.pop_back();
            visited[row - 1][col] = 0;
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends
