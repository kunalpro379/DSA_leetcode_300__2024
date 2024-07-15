class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int oddcount = 0;
        for (int num : arr)
        {
            if (num % 2 != 0)
            {
                oddcount++;
                if (oddcount == 3)
                {
                    return true;
                    break;
                }
            }
            else
                oddcount = 0;
        }
        return false;
    }
};