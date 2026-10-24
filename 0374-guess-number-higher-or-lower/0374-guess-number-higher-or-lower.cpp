/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long l = 1, r = n, m;
        int flag;
        while (l <= r) {
            m = (l + r) / 2;
            flag = guess(m);
            if (flag == -1)
                r = m - 1;
            else if (flag == 1)
                l = m + 1;
            else
                return m;
        }
        return l;
    }
};