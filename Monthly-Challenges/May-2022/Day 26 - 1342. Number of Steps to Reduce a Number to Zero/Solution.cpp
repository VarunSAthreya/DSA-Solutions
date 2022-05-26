class Solution
{
public:
    int numberOfSteps(int num)
    {
        int count = 0;
        if (num > 0)
            count = -1; // Because when 1 becomes 1 we should only substract not divide
        while (num)
        {
            if (num & 1) // 1
                count += 2;
            else // 0
                count++;
            num >>= 1; // Right Shift by 1
        }

        return count;
    }
};
