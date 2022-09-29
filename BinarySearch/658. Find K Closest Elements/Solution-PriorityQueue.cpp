// Brute
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>> pq;
        pq.push({abs(x - arr[0]), arr[0]});

        for (int i = 1; i < arr.size(); i++)
        {
            if (pq.size() < k)
            {
                pq.push({abs(arr[i] - x), arr[i]});
            }
            else
            {
                auto pr = pq.top();

                int top = pr.second;
                int prev = pr.first, curr = abs(arr[i] - x);

                if (curr < prev || (curr == prev && arr[i] < top))
                {
                    pq.pop();
                    pq.push({curr, arr[i]});
                }
            }
        }

        vector<int> res;
        while (!pq.empty())
            res.push_back(pq.top().second), pq.pop();

        sort(res.begin(), res.end());
        return res;
    }
};

// Changes as the array is sorted:

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {

        int n = arr.size();
        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {
            if (pq.size() != k)
                pq.push(arr[i]);
            else
            {
                if (abs(arr[i] - x) < abs(pq.top() - x))
                    pq.pop(), pq.push(arr[i]);
            }
        }

        while (pq.size())
            ans.push_back(pq.top()), pq.pop();

        return ans;
    }
};
