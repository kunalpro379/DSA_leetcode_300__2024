class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        int i = 0;
        int j = 0;
        int slen = s.length();
        int tlen = t.length();
        while (i < slen && j < tlen)
        {
            if (s[i] == t[j])
                j++;
            i++;
        }
        return tlen - j;
    }
};