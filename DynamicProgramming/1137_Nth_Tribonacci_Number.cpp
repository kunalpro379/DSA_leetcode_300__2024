class Solution
{
public:
    //////reccursive/////////
    // int tribonacci(int n) {
    //     if(n==0) return 0;
    //     if(n==1||n==2) return 1;
    //     return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    // }
    ///////memorized//////////

    int helper(int n, vector<int> &memo)
    {
        if (memo[n] != -1)
            return memo[n];
        memo[n] = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
        return memo[n];
    }
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        vector<int> memo(n + 1, -1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        return helper(n, memo);
        ;
    }

    /////////Tabulation//////////////
    /*
          int tribonacci(int n) {
              if(n==1)return 0;
              if(n==1||n==2)return 1;
              vector<int>dp(n+1);
              dp[0]=0;
              dp[1]=1;
              dp[2]=1;
              for(int i=3;i<=n;i++)
                  dp[i]=dp[i-1]+dp[i-2]+dp[i-3];

          return dp[n];
  }
  */
};