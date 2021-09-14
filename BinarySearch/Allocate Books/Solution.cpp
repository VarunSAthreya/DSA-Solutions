bool allocate(vector<int> &A, int B, int mid)
{
    int score = 0, person = 1;
    for (auto it : A)
    {
        if (score + it > mid)
        {
            score = it;
            person++;
            if (score > mid)
                return false;
        }
        else
        {
            score += it;
        }
    }

    // If person = 0, then person < B
    return person <= B;
}

int Solution::books(vector<int> &A, int B)
{
    if (B > A.size())
        return -1;

    int low = A[0];
    int high = 0;
    for (auto it : A)
    {
        high += it;
        low = min(low, it);
        // can also be done as: `low = max(low, it);` to reduce TC
    }

    int res = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (allocate(A, B, mid))
        {
            high = mid - 1;
            res = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}
