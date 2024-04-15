class Solution {
public:
    string removeKdigits(string num, int k) {
         cout<<"solution 1";
        // stack<char>stk;
        // for(char digit: num){
        //     while(!stk.empty()&&k>0&& stk.top()>digit){
        //         stk.pop();
        //        k--;
        //     }
        //     stk.push(digit);
        // }
        // while(k>0&& !stk.empty()){stk.pop(); k--;}
        // string res;
        // while(!stk.empty()){res=stk.top()+res;  stk.pop();}

        // int i=0;
        // while(i<res.length()&&res[i]=='0'){
        //     i++;
        // }
        // res=res.substr(i);
        // return res.empty()?"0":res;

        cout<<"solution 2";
        vector<char>vector;
        for(char digit: num){
            while(!vector.empty()&&k>0&&vector.back()>digit){
                vector.pop_back();
                k--;

            }
            vector.push_back(digit);
        }
         while (k > 0 && !vector.empty()) {
            vector.pop_back();
            k--;
        }
        
        std::string res;
        for (char d : vector) {
            res += d;
        }
        
        int i = 0;
        while (i < res.length() && res[i] == '0') {
            i++;
        }
        res = res.substr(i);
        
        return res.empty() ? "0" : res;
     }
};