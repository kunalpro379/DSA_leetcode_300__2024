class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = (s[0] == '0') ? 0 : 1;
        for (int i = 2; i <= n; i++)
        {
            if (s[i - 1] != '0')
                dp[i] += dp[i - 1];

            int twoDig = stoi(s.substr(i - 2, 2)); // extract substring of two characters
            if (twoDig >= 10 && twoDig <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};