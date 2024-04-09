class Solution {
public:
    bool checkValidString(string s) {
       stack<int >LeftP,stars;
       for(int i=0;i<s.length();i++){
                if(s[i]=='('){
                    LeftP.push(i);
                }
                else if(s[i]=='*'){
                    stars.push(i);
                }
                else{//s[i]==')'
                    if(!LeftP.empty()){
                        LeftP.pop();
                    }
                    else if (!stars.empty()){
                        stars.pop();
                    }
                    else{return false;}
                }
       }
       while(!LeftP.empty()&& !stars.empty()){
            if(LeftP.top()>stars.top()){
                return false;
            }
            LeftP.pop();
            stars.pop();
       }
       return LeftP.empty();
    }
};