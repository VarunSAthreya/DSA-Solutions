class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int res = 0;   // resultant total time after removal of all similar consecutive balloons
        int total = 0; // total time of a group of similar color balloons
        int high = 0;  // high is the highest time required to remove a balloon from the group
        int ind = 0;   // ind is the index of the similar color balloons
        int i = 0;     // i is the index of the current balloon

        // * LOGIC: Traverse through the string and find the group of similar color balloons, and except the highest time required to remove a balloon from the group remove all the balloons and add their total time to the result.

        while (i < n)
        {
            ind = i, total = 0, high = 0;
            while (colors[ind] == colors[i])
            {
                total += neededTime[ind];
                high = max(high, neededTime[ind]);
                ind++;
            }

            res += (total - high);
            i = ind;
        }

        return res;
    }
};
