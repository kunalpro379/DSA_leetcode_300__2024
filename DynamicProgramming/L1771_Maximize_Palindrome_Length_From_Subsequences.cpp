class Solution
{
public:
    int ans = 0;

    int memo(string &s, int l, int r, int n, int m, vector<vector<int>> &dp)
    {
        if (l > r)
            return 0; // Fix this condition
        if (l == r)
            return 1;
        if (dp[l][r] != -1)
            return dp[l][r];

        if (s[l] == s[r])
        {
            // Include both characters in the palindrome
            dp[l][r] = 2 + memo(s, l + 1, r - 1, n, m, dp);
            if (l < n && r >= n)
            {
                ans = max(ans, dp[l][r]);
            }
        }
        else
        {
            dp[l][r] = max(memo(s, l + 1, r, n, m, dp), memo(s, l, r - 1, n, m, dp));
        }

        return dp[l][r];
    }

    int longestPalindrome(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        string s = word1 + word2;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        memo(s, 0, s.size() - 1, n, m, dp);
        return ans; // Return the maximum length of the palindrome found
    }
};
