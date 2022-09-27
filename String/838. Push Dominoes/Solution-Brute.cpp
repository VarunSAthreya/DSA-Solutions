class Solution
{
public:
    string pushDominoes(string s)
    {
        string res = s;
        int n = s.size();

        do
        {
            s = res; // s is the previous state
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'R') // if right push
                {
                    if (i + 1 < n && s[i + 1] == '.') // if there is next domino & if next domino is not pushed
                        if (i + 2 < n)
                        {                         // if there is next to the next domino
                            if (s[i + 2] != 'L')  // if the next to the next domino is not left push
                                res[i + 1] = 'R'; // push the next domino
                        }
                        else
                            res[i + 1] = 'R'; // push the next domino as there is not next to the next domino
                }
                else if (s[i] == 'L') // if the domino has left push
                {
                    if (i - 1 >= 0 && s[i - 1] == '.') // checking if there is previous domino & if previous domino has no push
                        if (i - 2 >= 0)
                        {                         // if there is a previous domino to the previous domino
                            if (s[i - 2] != 'R')  // if the previous to the previous domino is not right push
                                res[i - 1] = 'L'; // push the previous domino
                        }

                        else
                            res[i - 1] = 'L'; // push the previous domino as there is no previous to the previous domino
                }
            }
        } while (res != s); // check if the state is changed

        return res;
    }
};
