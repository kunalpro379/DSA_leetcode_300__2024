class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1=s1.length(), len2=s2.length();
        if(len1>len2){
            return false;
        }
        unordered_map<char, int>s1F, winF;
        for(char &C: s1){s1F[C]++;}
        int L=0,R=0;
        while(R<len2){//iterating thrugh s2
            char current=s2[R];
            winF[current]++;
            while(R-L+1>len1){
                    char leftChar=s2[L];
                    winF[leftChar]--;
                    if(winF[leftChar]==0){winF.erase(leftChar);}

                    L++;
        

            }
        if(R-L+1==len1&&winF==s1F)
        return true;

        R++;
        }
        return false;
    }
};