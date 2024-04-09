class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>targetFreq;
        for(char &C:t){
            targetFreq[C]++;
        }
        int left=0, right  =0;
        int minWindowLen=INT_MAX;
        int minWindowStart=0;
        int reqChars=targetFreq.size();
        int formedChars=0;
        unordered_map<char, int>WindowFreq;
        while(right< s.length()){
            char currentChar=s[right];
            WindowFreq[currentChar]++;  
            //checking the current char if uit forms the target stiring
            if(targetFreq.count(currentChar)&& WindowFreq[currentChar]==targetFreq[currentChar])
                formedChars++;

            while(left<=right&&formedChars==reqChars){
                if(right-left+1<minWindowLen){
                    minWindowLen=right-left+1;
                    minWindowStart=left;
                }
                char leftChar=s[left];
                WindowFreq[leftChar]--;

                if(targetFreq.count(leftChar)&& WindowFreq[leftChar]<targetFreq[leftChar]){formedChars--;}
                left++;
            }
            right++;


        }
        return (minWindowLen==INT_MAX)? "" : s.substr(minWindowStart, minWindowLen);
    }

};