// { Driver Code Starts
//Initial Template for C
#include <bits/stdc++.h>

// } Driver Code Ends
//User function Template for C

//Function to merge the arrays.
void merge(int arr1[], int arr2[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[n] > arr2[m])
            {
                swap(arr1[n], arr2[m]);
                sort(arr2, arr2 + m);
            }
        }
    }
}

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d", &n);
        scanf("%d", &m);
        int *arr1;
        arr1 = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            scanf("%d", &arr1[i]);
        int *arr2;
        arr2 = (int *)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++)
            scanf("%d", &arr2[i]);

        merge(arr1, arr2, n, m);
        for (int i = 0; i < n; i++)
            printf("%d ", arr1[i]);
        for (int i = 0; i < m; i++)
            printf("%d ", arr2[i]);
        printf("\n");
    }
    return 0;
} // } Driver Code Ends
