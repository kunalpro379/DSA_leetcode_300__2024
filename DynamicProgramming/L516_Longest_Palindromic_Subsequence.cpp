class Solution
{
public:
    int SpaceOptmDp(string &text1, string &text2)
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

    int longestPalindromeSubseq(string s)
    {
        string p = s;
        reverse(p.begin(), p.end());
        return SpaceOptmDp(s, p);
    }
};