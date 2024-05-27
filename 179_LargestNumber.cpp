class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> numsStr;
        for (int num : nums)
            numsStr.push_back(to_string(num));

        // custom comparator
        sort(numsStr.begin(), numsStr.end(), [](const string &a, const string &b)
             { return a + b > b + a; });
        // for(int i=0;i<numsStr.size();i++){
        //     for(int j=i+1;j<numsStr.size();j++){
        //         if(comp(numsStr[i],numsStr[j]))
        //             swap(numsStr[i],numsStr[j]);
        //     }
        // }
        //
        if (numsStr[0] == "0")
            return "0";
        string res;
        for (const string &numStr : numsStr)
        {
            res += numStr;
        }
        return res;
    }
};