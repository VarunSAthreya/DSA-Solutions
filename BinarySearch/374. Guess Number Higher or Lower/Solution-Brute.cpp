/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int num = guess(n);
        int res = n;

        while (num != 0)
        {
            if (num == -1)
                res--;
            else if (num == 1)
                res++;

            num = guess(res);
        }

        return res;
    }
};
