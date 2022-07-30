vector<int> Solution::repeatedNumber(const vector<int> &A)
{
    vector<int> res;

    int XOR = 1;
    int n = A.size();
    // TO XOR all the elements 1-n
    for (int i = 2; i <= n; i++)
    {
        XOR ^= i;
    }
    // TO XOR all the elements in the array
    for (int i : A)
    {
        XOR ^= i;
    }

    int setBit = XOR & ~(XOR - 1); // TO get the left most set bit of the number
    int s1 = 0;
    int s2 = 0;

    // To separate the two sets of elements from the array
    for (int i : A)
    {
        if (i & setBit)
        {
            s1 ^= i;
        }
        else
        {
            s2 ^= i;
        }
    }
    // To separate the two sets of number from 1-n
    for (int i = 1; i <= n; i++)
    {
        if (i & setBit)
        {
            s1 ^= i;
        }
        else
        {
            s2 ^= i;
        }
    }

    // To find the missing and repeating number
    for (int i : A)
    {
        if (i == s1)
        {
            return vector<int>{s1, s2};
        }
        if (i == s2)
        {
            return vector<int>{s2, s1};
        }
    }

    // return vector<int> {s2,s1};
}
