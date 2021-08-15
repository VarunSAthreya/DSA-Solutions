// Wont work because of exponential time complexity
class Solution
{
public:
    int countPaths(int i, int j, int m, int n)
    {
        if (i == m - 1 && j == n - 1)
            return 1;

        if (i >= m || j >= n)
            return 0;

        return countPaths(i + 1, j, m, n) + countPaths(i, j + 1, m, n);
    }

    int uniquePaths(int m, int n)
    {
        return countPaths(0, 0, m, n);
    }
};
