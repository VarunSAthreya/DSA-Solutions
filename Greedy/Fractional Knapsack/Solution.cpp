// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    static bool comparator(Item a, Item b)
    {
        return (((double)a.value / a.weight) > ((double)b.value / b.weight));
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comparator);

        double accumulatedWeight = 0;
        double res = 0;

        for (int i = 0; i < n; i++)
        {
            if (accumulatedWeight + arr[i].weight <= W)
            {
                accumulatedWeight += arr[i].weight;
                res += arr[i].value;
            }
            else
            {
                int rem = W - accumulatedWeight;
                res += ((double)arr[i].value / arr[i].weight) * rem;
                accumulatedWeight += rem;
                break;
            }
        }

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends
