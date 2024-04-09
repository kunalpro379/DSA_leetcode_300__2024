class Solution {
public:
    int romanToInt(string s) {
  unordered_map<char, int> romanToIntMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int res=0;
        int prev=0;
        for (int i=s.length()-1;i>=0;i--){
            int current=romanToIntMap[s[i]];
            if(current<prev){
                res-=current;
            }
            else{
                    res+=current;
            }
            prev=current;
        }
        return res;
    }
};