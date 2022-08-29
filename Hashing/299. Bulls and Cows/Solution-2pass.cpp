class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bull = 0;
        int n = secret.size();
        unordered_map<char, int> mpp;

        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
                bull++;
            else
                mpp[secret[i]]++;
        }

        int cow = 0;
        for (int i = 0; i < n; i++)
        {
            if (guess[i] != secret[i] && mpp.find(guess[i]) != mpp.end())
            {
                mpp[guess[i]]--;
                if (mpp[guess[i]] == 0)
                    mpp.erase(guess[i]);
                cow++;
            }
        }

        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};
