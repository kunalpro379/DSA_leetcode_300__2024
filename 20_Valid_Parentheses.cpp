class Solution
{
public:
    bool isValid(string s)
    {
        std::unordered_map<char, char> matchingBraq = {
            {')', '('},
            {'}', '{'},
            {']', '['}};
        stack<char> stk;
        for (char c : s)
        {
            if (matchingBraq.count(c))
            {
                if (stk.empty() || stk.top() != matchingBraq[c])
                {
                    return false;
                }

                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};