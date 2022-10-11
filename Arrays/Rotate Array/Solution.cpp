class Solution
{
public:
    int gcd(int a, int b)
    {
        if (b > a)
            return gcd(b, a);

        if (b == 0)
            return a;

        return gcd(b, a % b);
    }

    void rotateArr(int arr[], int d, int n)
    {
        d = d % n; // remove extra rotations

        int sets = gcd(n, d);
        for (int i = 0; i < sets; i++)
        {
            int tmp = arr[i];
            int j = i;

            while (true)
            {
                int k = j + d;
                if (k >= n)
                    k = k - n;
                if (k == i)
                    break;

                arr[j] = arr[k];
                j = k;
            }
            arr[j] = tmp;
        }
    }
};
