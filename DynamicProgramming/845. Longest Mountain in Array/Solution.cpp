class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int res = 0;
        int n = arr.size();
        if (n < 3)
            return res;

        for (int i = 0; i < n; i++)
        {
            int j = i;
            int cnt = 1;
            bool flag = false;

            // increasing
            while (j < n - 1 && arr[j] < arr[j + 1])
            {
                cnt++;
                j++;
            }
            // decreasing
            while (i != j && j < n - 1 && arr[j] > arr[j + 1])
            {
                flag = true;
                cnt++;
                j++;
            }

            // save solution
            if (i != j && flag)
            {
                res = max(res, cnt);
                j--; // last value is overlapping
            }

            i = j;
        }

        return res;
    }
};
