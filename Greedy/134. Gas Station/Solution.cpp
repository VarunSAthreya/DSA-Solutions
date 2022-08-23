/*
First find the gas comsume of each station i.e (gas[i] - cost[i]). If `total` consume of all the gas stations is -ve then there is no solution present, if its 0 ir +ve we can find a solution.
Then we loop through the array and find the consume for each station but in this, if the individual consume is -ve then we reset the `sum` to 0 and start from the next station, like this well find a station on further to which the sum would always be +ve and thats the solution.
*/

// O(2N) time
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int n = gas.size();

        for (int i = 0; i < n; i++)
            total += (gas[i] - cost[i]);

        if (total < 0)
            return -1;

        int sum = 0, ind = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (gas[i] - cost[i]);
            if (sum < 0)
            {
                sum = 0;
                ind = i + 1;
            }
        }

        return ind;
    }
};

// O(N) time
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int total = 0;
        int n = gas.size();

        int curr_sum = 0, ind = 0;
        for (int i = 0; i < n; i++)
        {
            curr_sum += (gas[i] - cost[i]);
            total += (gas[i] - cost[i]);
            if (curr_sum < 0)
            {
                curr_sum = 0;
                ind = i + 1;
            }
        }

        return total < 0 ? -1 : ind;
    }
};
