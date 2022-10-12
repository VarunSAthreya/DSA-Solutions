#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int a = 0, b = 0;
        int count = 1;
        while (a < n && b < m)
        {

            if (arr1[a] < arr2[b])
            {
                if (count == k)
                    return arr1[a];
                a++;
            }
            else
            {
                if (count == k)
                    return arr2[b];
                b++;
            }
            count++;
        }

        for (int i = a; i < n; i++)
        {
            if (count == k)
                return arr1[i];
            count++;
        }
        for (int i = b; i < m; i++)
        {
            if (count == k)
                return arr2[i];
            count++;
        }

        return -1;
    }
};
