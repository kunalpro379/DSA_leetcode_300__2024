class Solution
{
public:
    //     int numTilings(int n) {
    //         const int mod=1000000007;
    //         if(n==1) return 1;
    //         if(n==2) return 2;
    //         int dpj=1;
    //         vector<int>dp(n+1);

    //         dp[1]=1;
    //         dp[2]=2;
    //         for(int i=3;i<=n;i++){
    //             //for domino tile
    //             if(n<3)
    //                 dp[i]=(dp[i-1]*2)%mod;
    //             //adding the ways of tromino tile
    //             if(n=3) dp[i]=(dp[i-1]*2+dpj)%mod;
    //             if(n>3)dp[]
    //             dpj++;

    //             if(i%2!=0&&n!=3&&n!=1) dp[i]=(dp[i]+2*(dp[i-2])+1)%mod;

    //         }
    //         return dp[n];

    //     }

    int numTilings(int n)
    {

        return dfs(n, 0, 0);
    }
    int dfs(int n, int i, int state)
    {
        // tiled entire boeard
        if (i == n)
            return 1;
        if (i > n)
            return 0;
        long long ans = 0;

        if (state == 0)
        {
            // leaving the colum
            ans += dfs(n, i + 1, 0);
            // placing the horizontal domino
            ans += dfs(n, i + 1, 1);
        }
        else if (state == 1)
        {
            // leaving the column
            ans += dfs(n, i + 1, 0);
            // placing the horizontal domino
            if (i + 1 < n)
                ans += dfs(n, i + 2, 0);
        }
        else if (state == 2)
        {
            ans += dfs(n, i + 1, 0); // leaving the column
            ans += dfs(n, i + 1, 0);

            // placing verticle domino or trimino
            // if(i<n)ans+=dfs(n, i+1, 1);
            // if(i+1<n)ans+=dfs(n, i+2,0);
            ans += dfs(n, i + 2, 0);

            if (i + 2 < n)
                ans += dfs(n, i + 2, 0);
        }
        return ans % 1000000007;
    }
};