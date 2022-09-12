class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        string res = "";
        vector<int> hash(26, 0);
        queue<char> q;

        for (int i = 0; i < A.size(); i++)
        {
            if (hash[A[i] - 'a'] == 0)
            {
                hash[A[i] - 'a']++;

                if (q.empty())
                    res += A[i];
                else
                    res += q.front();

                q.push(A[i]);
            }
            else
            {
                hash[A[i] - 'a']++;
                while (!q.empty() && hash[q.front() - 'a'] > 1)
                    q.pop();

                if (q.empty())
                    res += '#';
                else
                    res += q.front();
            }
        }
        return res;
    }
};
