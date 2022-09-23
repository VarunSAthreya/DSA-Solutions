class Solution
{
public:
    int numberOfBits(int n)
    {
        //*int leadingZeros = __builtin_clz(n);
        //* return 32 - leadingZeros;
        return log2(n) + 1; // slower
    }

    int concatenatedBinary(int n)
    {
        long res = 0, mod = 1e9 + 7;
        //* int len = 0;

        for (int i = 1; i <= n; i++)
        {
            //* if(__builtin_popcount(i) == 1) ++len;
            res = ((res << len) % mod + i) % mod;
        }

        return res;
    }
};
