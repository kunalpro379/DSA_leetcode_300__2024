class Solution {
public:
    int maxDepth(string s) {
        stack<char>parenthesesStack;
        int maxDepth=0;
        for(char c:s){
            if(c=='('){
            parenthesesStack.push(c); 
            maxDepth=max(maxDepth, static_cast<int>(parenthesesStack.size()));
            }
            else if(c==')'){
                parenthesesStack.pop();
            }
        }
    return maxDepth;
    }
};