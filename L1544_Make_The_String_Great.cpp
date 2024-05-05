#include <string>
#include <stack>
#include <cmath>

class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;

        for (char c : s) {
            if (!stk.empty() && abs(stk.top() - c) == 32) {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        
        string res;
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        
        return res;
    }
};
