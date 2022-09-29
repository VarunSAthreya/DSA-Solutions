class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int l = 0, r = n - 1;

        int val = arr[0], idx = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            int curDiff = abs(arr[m] - x);
            int resDiff = abs(val - x);

            if (curDiff < resDiff || (curDiff == resDiff && arr[m] < val))
            {
                val = arr[m];
                idx = m;
            }

            if (arr[m] < x)
            {
                l = m + 1;
            }
            else if (arr[m] > x)
            {
                r = m - 1;
            }
            else
            {
                break;
            }
        }

        l = r = idx;
        for (int i = 0; i < k - 1; i++)
        {
            if (l == 0)
            {
                r++;
            }
            else if (r == n - 1 || x - arr[l - 1] <= arr[r + 1] - x)
            {
                l--;
            }
            else
            {
                r++;
            }
        }

        return vector<int>(arr.vector::begin() + l, arr.vector::begin() + r + 1);
    }
};
