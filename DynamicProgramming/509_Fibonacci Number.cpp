class Solution
{
public:
    // int fib(int n) {
    //     if(n==0)return 0;
    //     if(n==1) return 1;
    //     vector<int>dp(n+1);
    //     dp[0]=0;
    //     dp[1]=1;
    //     for(int i=2;i<=n;i++)
    //         dp[i]=dp[i-1]+dp[i-2];

    //     return dp[n];
    // }
    ////more optimized
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int prev1 = 0;
        int prev2 = 1;
        int current;

        for (int i = 2; i <= n; i++)
        {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }
        return current;
    }

    /*
//reccrssive
    */

    /*
//memorized
    */
};