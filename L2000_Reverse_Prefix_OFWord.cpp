class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        int j=word.find(ch);
        if(j!=string::npos){
            while(i<j){
                swap(word[i],word[j]);
                i++;
                j--;
            }
        }return word;
    }
};