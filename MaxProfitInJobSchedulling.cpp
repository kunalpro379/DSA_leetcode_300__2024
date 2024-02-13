#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Wrong solution
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        sort(profit.begin(), profit.end());
        vector<int> id;

        int maxTime = 0;
        int n = profit.size();
        for(int i = 0; i < n; i++){
            maxTime = max(maxTime, endTime[i] - startTime[i]);
            id.push_back(i);
        }
        
        vector<int> slot(maxTime + 1, -1);
        int finalProfit = 0;
        for(int i = 0; i < n; i++){
            int currJob = id[i];
            int dead = endTime[currJob] - startTime[currJob];
            for(int p = dead; p > 0; p--){
                if(slot[p] == -1){
                    slot[p] = currJob;
                    finalProfit += profit[currJob];
                    break;
                }
            }
        }
        
        return finalProfit;
    }
};
