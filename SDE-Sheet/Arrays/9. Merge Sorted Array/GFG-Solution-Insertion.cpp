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
