class Solution
{
public:
    int solve(int start, int end, vector<vector<int>> &memo)
    {
        if (start >= end)
            return 0;
        int min_cost = INT_MAX;
        if (memo[start][end] != -1)
            return memo[start][end];
        for (int k = start; k <= end; k++)
        {
            int cost = k; // cost for gussing k
            int left_cost = solve(start, k - 1, memo);
            int right_cost = solve(k + 1, end, memo);
            // max cost of leftcost and rightcost
            int maxcostlr = cost + max(left_cost, right_cost);
            min_cost = min(min_cost, maxcostlr);
        }
        memo[start][end] = min_cost;
        return min_cost;
    }

    int getMoneyAmount(int n)
    {
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        return solve(1, n, memo);
    }
};