class Solution
{
public:
    bool isNice(string &s)
    {
        unordered_set<char> CharSet(s.begin(), s.end());
        for (char c : s)
        {
            if (CharSet.count(tolower(c)) == 0 || CharSet.count(toupper(c)) == 0)
                return false;
            // if (s.count(tolower(c)) == charSet.count(tolower(c)))
            //     return true;
        }
        return true;
    }
    string longestNiceSubstring(string s)
    {
        int n = s.size();
        if (n < 2)
            return "";
        // for(int i=0;i<n;i++){
        //     if(!isNice(s)){
        //         string left=longestNiceSubstring(s.substr(0,i));
        //         string right=longestNiceSubstring(s.substr(i+1));
        //         return left.size()>=right.size()?left:right;

        //     }
        // }return s;
        string longestNice;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                string substr = s.substr(i, j - i);
                if (isNice(substr) && substr.size() > longestNice.size())
                {
                    longestNice = substr;
                }
            }
        }
        return longestNice;
    }
};