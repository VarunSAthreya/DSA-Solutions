class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> res;
        if (n == 0)
            return res;

        int mx = INT_MIN;
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            mx = max(mx, arr[i]);
            q.push(arr[i]);
        }
        res.push_back(mx);

        for (int i = k; i < n; i++)
        {
            auto front = q.front();
            q.pop();
            q.push(arr[i]);

            if (front == mx)
            {
                queue<int> rep(q);
                int tmp = INT_MIN;
                while (!rep.empty())
                {
                    tmp = max(rep.front(), tmp);
                    rep.pop();
                }
                mx = tmp;
            }
            else
            {
                mx = max(mx, arr[i]);
            }

            res.push_back(mx);
        }

        return res;
    }
};
