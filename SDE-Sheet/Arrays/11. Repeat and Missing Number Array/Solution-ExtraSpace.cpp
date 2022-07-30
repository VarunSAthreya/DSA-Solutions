vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    int n = A.size() + 1;

    vector<int> substitute(n, 0);
    vector<int> res(2);

    for (int i = 0; i < A.size(); i++)
    {
        substitute[A[i]]++;
    }

    for (int i = 1; i <= A.size(); i++)
    {
        if (substitute[i] == 0)
        {
            res[1] = (i);
        }
        if (substitute[i] > 1)
        {
            res[0] = (i);
        }
    }

    return res;
}
