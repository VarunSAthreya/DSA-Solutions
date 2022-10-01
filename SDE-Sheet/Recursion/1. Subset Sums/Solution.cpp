#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        sort(arr.begin(), arr.end(), greater<int>());
        vector<int> ans;

        sum(arr, ans, 0, 0);

        return ans;
    }
    void sum(vector<int> &arr, vector<int> &ans, int ind, int add)
    {
        if (ind == arr.size())
        {
            ans.push_back(add);
            return;
        }

        sum(arr, ans, ind + 1, add);
        sum(arr, ans, ind + 1, add + arr[ind]);
    }
};
