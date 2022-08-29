// MAP
class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0, cow = 0;
        int n = secret.size();
        unordered_map<char, int> mpp;

        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bull++;
            else
            {
                if (mpp[secret[i]]++ < 0)
                    cow++;
                if (mpp[guess[i]]-- > 0)
                    cow++;
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

// Vector

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0, cow = 0;
        int n = secret.size();
        vector<int> mpp(10);

        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bull++;
            else
            {
                if (mpp[secret[i] - '0']++ < 0)
                    cow++;
                if (mpp[guess[i] - '0']-- > 0)
                    cow++;
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
