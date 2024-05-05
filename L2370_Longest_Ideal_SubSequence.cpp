#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> lastOccur(26, -1); 
        vector<int> dp(n, 1); 
        int ans = 1; 

        for (int i = 0; i < n; ++i) {
            int currChar = s[i] - 'a'; 
            for (int prevChar = max(0, currChar - k); prevChar <= min(25, currChar + k); ++prevChar) {
                if (lastOccur[prevChar] != -1) {
                    int diff = abs(currChar - prevChar);
                    if (diff <= k) {
                        dp[i] = max(dp[i], dp[lastOccur[prevChar]] + 1);
                    }
                }
            }
            lastOccur[currChar] = i;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

