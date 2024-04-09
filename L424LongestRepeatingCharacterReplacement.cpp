class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>freq;
        int left=0, maxFreq=0, maxlen=0;
        for(int right=0;right<s.length();right++)
        {
            char currentChar=s[right];
            freq[currentChar]++;
            maxFreq=max(maxFreq, freq[currentChar]);//maxfreq wirhin the window
            if(right-left+1-maxFreq>k){//remaining chars
                    char leftChar=s[left];
                    freq[leftChar]--;
                    left++;
            }
            maxlen=max(maxlen, right-left+1);
        }
        return maxlen;
    }
};