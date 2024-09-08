
/*
class Solution {
public:
    void maxproffitFn(vector<int>& prices, int i, int& minprice, int& maxprofit) {
        // base case
        if (i == prices.size()) return;

        if (prices[i] < minprice) minprice = prices[i];
        int todaysprofit = prices[i] - minprice;
        if (todaysprofit > maxprofit) maxprofit = todaysprofit;

        maxproffitFn(prices, i + 1, minprice, maxprofit);
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minprice = prices[0];
        int maxprofit = 0;

        maxproffitFn(prices, 0, minprice, maxprofit);
        return maxprofit;
    }
};
*/
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mini = prices[0];
        int prof = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - mini;
            prof = max(prof, diff);
            mini = min(mini, prices[i]);
        }
        return prof;
    }
};