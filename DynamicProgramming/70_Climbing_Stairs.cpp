
class Solution
{
public:
    // int solve(long long nStairs,int currStair){
    // if(currStair==nStairs){return 1;}

    // if(currStair>nStairs)
    // return 0;

    // return (solve(nStairs, currStair+1)+solve(nStairs, currStair+2));

    // }
    // int climbStairs(int n) {
    //     int ans=solve(n,0);
    //     return ans;
    // }
    // int climbStairs(int n) {

    //     if(n==1)return 1;
    //     if(n==2)return 2;
    //     return climbStairs(n-1)+climbStairs(n-2);
    // }

    // memorized///////////
    int helper(int n, vector<int> &memo)
    {
        if (memo[n] != -1)
            return memo[n];
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }
    int climbStairs(int n)
    {

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        vector<int> memo(n + 1, -1);
        memo[1] = 1;
        memo[2] = 2;
        return helper(n, memo);
    }

    ////tabulation//////
    /*
    int climbStairs(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    std::vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
    */
};