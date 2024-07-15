// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         if(x>=y){
//             return removeSubString(s, 'a', 'b', x)+ removeSubString(s, 'b', 'a', y);
//         }
//         else{
//             return removeSubString(s, 'b', 'a', y)+removeSubString(s, 'a', 'b', x);
//         }
//     }

//     int removeSubString(string &s, char c1, char c2, int points){
//             stack<char>st;
//             int score=0;
//             for(char c:s){
//                 if(!st.empty()&& st.top()==c1&& c==c2){
//                     st.pop();
//                     score+=points;
//                 }else st.push(c);
//             }
//             string remaining="";
//             while(!st.empty()){
//                 remaining=st.top()+remaining;
//                 st.pop();
//             }
//             s=remaining;
//             return score;
//     }
// };
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        int totalScore = 0;
        if (x >= y)
        {
            totalScore += removeSubString(s, 'a', 'b', x);
            totalScore += removeSubString(s, 'b', 'a', y);
        }
        else
        {
            totalScore += removeSubString(s, 'b', 'a', y);
            totalScore += removeSubString(s, 'a', 'b', x);
        }
        return totalScore;
    }

private:
    int removeSubString(string &s, char c1, char c2, int points)
    {
        stack<char> st;
        int score = 0;
        for (char c : s)
        {
            if (!st.empty() && st.top() == c1 && c == c2)
            {
                st.pop();
                score += points;
            }
            else
            {
                st.push(c);
            }
        }

        string remaining;
        while (!st.empty())
        {
            remaining.push_back(st.top());
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());
        s = remaining;

        return score;
    }
};