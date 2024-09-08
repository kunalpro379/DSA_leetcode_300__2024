class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>> charStack;
        for (char ch : s)
        {
            if (!charStack.empty() && charStack.top().first == ch)
                charStack.top().second++;

            else
                charStack.push({ch, 1});

            if (charStack.top().second == k)
                charStack.pop();
        }
        string res = "";
        while (!charStack.empty())
        {
            // auto [char, count]=charStack.top();
            pair<char, int> p = charStack.top();
            charStack.pop();
            res.append(p.second, p.first);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};