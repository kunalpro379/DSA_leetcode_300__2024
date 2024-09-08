
// recursive solution

// class Solution {
// public:

// int solve(int index, int buy, vector<int>& prices){
//     if(index==prices.size()) return 0;
//     int prof=0;
//     if(buy ) {
//         int buy=(-prices[index])+solve(index+1,0,prices);
//         int skip=0+ solve(index+1, 1,prices);
//         prof=max(buy,skip);
//         }
//     else {
//          int buy=+prices[index]+solve(index+1,1,prices);
//         int skip=0+ solve(index+1, 0,prices);
//         prof=max(buy,skip);

//     }
//     return prof;
// }
//     int maxProfit(vector<int>& prices) {
//         return solve(0, 1, prices);
//     }
// };
// top down sol
class Solution
{
public:
    int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;
        if (dp[index][buy] != -1)
            return dp[index][buy];

        int prof = 0;
        if (buy)
        {
            int buy = (-prices[index]) + solve(index + 1, 0, prices, dp);
            int skip = 0 + solve(index + 1, 1, prices, dp);
            prof = max(buy, skip);
        }
        else
        {
            int buy = +prices[index] + solve(index + 1, 1, prices, dp);
            int skip = 0 + solve(index + 1, 0, prices, dp);
            prof = max(buy, skip);
        }
        return dp[index][buy] = prof;
    }

    // Tabulation bottom up approach
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int prof = 0;
                if (buy)
                {
                    int buyStock = -prices[index] + dp[index + 1][0];
                    int skip = 0 + dp[index + 1][1];
                    prof = max(buyStock, skip);
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][1];
                    int skip = 0 + dp[index + 1][0];
                    prof = max(sell, skip);
                }
                dp[index][buy] = prof;
            }
        }
        return dp[0][1];
    }

    // Space Optimization

    int SpaceOptim(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int prof = 0;
                if (buy)
                {
                    int buyStock = -prices[index] + next[0]; // dp[index + 1][0];
                    int skip = 0 + next[1];                  // dp[index + 1][1];
                    prof = max(buyStock, skip);
                }
                else
                {
                    int sell = prices[index] + next[1]; // dp[index + 1][1];
                    int skip = 0 + next[0];             // dp[index + 1][0];
                    prof = max(sell, skip);
                }
                // dp[index][buy] = prof;
                curr[buy] = prof;
            }
            next = curr;
        }
        return next[1]; // dp[0][1];
    }

    int maxProfit(vector<int> &prices)
    {
        // int n=prices.size();
        // vector<vector<int>>dp(n, vector<int>(2,-1));
        // return solve(0, 1, prices, dp);
        return SpaceOptim(prices);
    }
};
