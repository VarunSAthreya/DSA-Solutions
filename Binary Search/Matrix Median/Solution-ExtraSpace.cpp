int Solution::findMedian(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();

    vector<int> ds;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ds.push_back(A[i][j]);
        }
    }

    sort(ds.begin(), ds.end());

    return ds[ds.size() / 2];
}
