class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int cycleLen = 2 * (n - 1);
        int pos = time % cycleLen;
        if (pos < n)
            return pos + 1;
        else
        {
            return 2 * n - pos - 1;
        }
    }
};