class Solution
{
public:
    int lcs(string &word1, string &word2, int i, int j, vector<vector<int>> &memo)
    {
        if (i < 0 || j < 0)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (word1[i] == word2[j])
        {
            memo[i][j] = 1 + lcs(word1, word2, i - 1, j - 1, memo);
        }
        else
        {
            memo[i][j] = max(lcs(word1, word2, i - 1, j, memo), lcs(word1, word2, i, j - 1, memo));
        }

        return memo[i][j];
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int lcsLen = lcs(word1, word2, m - 1, n - 1, memo);
        return m + n - 2 * lcsLen;
    }
};