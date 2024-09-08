class Solution
{
public:
    int SpaceOptim(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<vector<int>> curr(2, vector<int>(3.0));
        vector<vector<int>> next(2, vector<int>(3.0));

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int prof = 0;
                    if (buy)
                    {
                        int buyStock = -prices[index] + next[0][limit];
                        int skip = 0 + next[1][limit];
                        prof = max(buyStock, skip);
                    }
                    else
                    {
                        int sell = prices[index] + next[1][limit - 1];
                        int skip = 0 + next[0][limit];
                        prof = max(sell, skip);
                    }
                    curr[buy][limit] = prof;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int> &prices)
    {
        return SpaceOptim(prices);
    }
};