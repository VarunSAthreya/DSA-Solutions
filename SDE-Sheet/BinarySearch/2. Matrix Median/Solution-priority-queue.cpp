int Solution::findMedian(vector<vector<int>> &A)
{
    int n = A.size(), m = A[0].size();

    priority_queue<int> pq;
    for (auto ar : A)
    {
        for (int i : ar)
            pq.push(i);
    }

    int mid = (n * m) / 2;

    while (mid--)
        pq.pop();

    return pq.top();
}
