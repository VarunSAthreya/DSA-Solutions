vector<int> missing_repeated_number(const vector<int> &A)
{
    long long int n = A.size();

    long long int S = (n * (n + 1)) / 2;
    long long int P = (n * (n + 1) * (2 * n + 1)) / 6;
    long long int missingNumber = 0, repeating = 0;

    for (int i = 0; i < A.size(); i++)
    {
        S -= (long long int)A[i];
        P -= (long long int)A[i] * (long long int)A[i];
    }

    missingNumber = (S + P / S) / 2;

    repeating = missingNumber - S;

    return vector<int>{repeating, missingNumber};
}
