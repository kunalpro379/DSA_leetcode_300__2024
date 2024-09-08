class Solution
{
public:
    unordered_map<string, bool> memo;

    bool solve(string s, string p)
    {
        string key = s + ',' + p;
        if (memo.find(key) != memo.end())
            return memo[key];

        if (p.length() == 0)
            return s.length() == 0;
        bool first_char_matched = false;
        if (s.length() > 0 && (p[0] == s[0] || p[0] == '.'))
            first_char_matched = true;
        if (p.length() >= 2 && p[1] == '*')
        {
            bool not_take = solve(s, p.substr(2));
            bool take = first_char_matched && solve(s.substr(1), p);
            memo[key] = not_take || take;
            return memo[key];
        }
        if (first_char_matched)
        {
            memo[key] = first_char_matched && solve(s.substr(1), p.substr(1));
            return memo[key];
        }
        memo[key] = false;
        return memo[key];
    }
    bool isMatch(string s, string p)
    {
        return solve(s, p);
    }
};