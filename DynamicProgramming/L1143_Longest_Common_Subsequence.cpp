class Solution
{
public:
    // Reccurssive Apch
    int lcsRec(string &text1, string &text2, int i, int j)
    {
        if (i == 0 || j == 0)
            return 0;
        if (text1[i - 1] == text2[j - 1])
            return 1 + lcsRec(text1, text2, i - 1, j - 1);
        else
            return max(lcsRec(text1, text2, i, j - 1), lcsRec(text1, text2, i - 1, j));
    }
    // Memorization
    int lcsMemo(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (text1[i - 1] == text2[j - 1])
            dp[i][j] = 1 + lcsMemo(text1, text2, i - 1, j - 1, dp);
        else
            dp[i][j] = max(lcsMemo(text1, text2, i, j - 1, dp), lcsMemo(text1, text2, i - 1, j, dp));
        return dp[i][j];
    }
    // Dynmic. prog.
    int lcsDp(string &text1, string &text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                // if(i==0||j==0) dp[i][j] = 0;

                if (text1[i] == text2[j])
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    // Space Optimized

    int SpaceOptmDp(string &text1, string text2)
    {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = prev[j - 1] + 1;
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            swap(prev, curr);
        }
        return prev[n];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        // return lcsRec(text1, text2, text1.size(), text2.size());
        // return lcsMemo(text1, text2, text1.size(), text2.size(),dp);
        // return lcsDp(text1, text2);
        return SpaceOptmDp(text1, text2);
    }
};