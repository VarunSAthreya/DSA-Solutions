// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    struct meeting
    {
        int start;
        int end;
    };
    static bool comaprator(struct meeting m1, meeting m2)
    {
        return m1.end < m2.end;
    }

    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        struct meeting meet[n];
        for (int i = 0; i < n; i++)
        {
            meet[i].start = start[i];
            meet[i].end = end[i];
        }

        sort(meet, meet + n, comaprator);

        int prev = INT_MIN;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            if (meet[i].start > prev)
            {
                prev = meet[i].end;
                res++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;

    //testcases
    cin >> t;
    while (t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        //adding elements to arrays start and end
        for (int i = 0; i < n; i++)
            cin >> start[i];
        for (int i = 0; i < n; i++)
            cin >> end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
