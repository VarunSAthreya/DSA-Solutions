
class Solution
{
public:
    static bool comparator(Item a, Item b)
    {
        return (((double)a.value / a.weight) > ((double)b.value / b.weight));
    }
    // Function to get the maximum total value in the knapsack.
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
