class Solution
{
public:
    vector<int> findErrorNums(vector<int> &A)
    {
        vector<int> res;

        int XOR = 0;
        int n = A.size();

        for (int i = 0; i < n; i++)
        {
            XOR ^= (i + 1); // TO XOR all the elements 1-n
            XOR ^= A[i];    // TO XOR all the elements in the array
        }

        int setBit = XOR & ~(XOR - 1); // TO get the left most set bit of the number
        int s1 = 0;
        int s2 = 0;

        for (int i = 0; i < n; i++)
        {
            // To separate the two sets of elements from the array
            if (A[i] & setBit)
                s1 ^= A[i];
            else
                s2 ^= A[i];

            // To separate the two sets of number from 1-n
            if ((i + 1) & setBit)
                s1 ^= (i + 1);
            else
                s2 ^= (i + 1);
        }

        // To find the missing and repeating number
        for (int i : A)
        {
            if (i == s1)
                return vector<int>{s1, s2};
            if (i == s2)
                return vector<int>{s2, s1};
        }

        return vector<int>{s2, s1}; // redundant
    }
};
