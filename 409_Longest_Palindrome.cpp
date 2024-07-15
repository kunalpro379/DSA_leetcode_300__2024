class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> charcnt;
        for (char c : s)
        {
            charcnt[c]++;
        }
        int len = 0;
        bool odd = false;

        for (const auto &it : charcnt)
        {
            int cnt = it.second;
            if (cnt % 2 == 0)
                len += cnt;
            else
            {
                len += cnt - 1;
                odd = true;
            }
        }
        if (odd)
        {
            len += 1;
        }
        return len;
    }
};