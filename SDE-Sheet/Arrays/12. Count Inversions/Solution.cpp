long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    long long i = left, j = mid, k = left;
    long long inv_cnt = 0;

    while ((i < mid) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            inv_cnt += (mid - i);
            temp[k++] = arr[j++];
        }
    }

    while (i < mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_cnt;
}

long long mergeSort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid = 0, inv_cnt = 0;

    if (right > left)
    {
        mid = (right + left) / 2;

        inv_cnt += mergeSort(arr, temp, left, mid);
        inv_cnt += mergeSort(arr, temp, mid + 1, right);

        inv_cnt += merge(arr, temp, left, mid + 1, right);
    }

    return inv_cnt;
}

long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    return mergeSort(arr, temp, 0, N - 1);
}
