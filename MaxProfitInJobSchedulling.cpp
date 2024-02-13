#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

//may be Wrong solution
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        sort(profit.begin(), profit.end());
        map<int , int >Jobs;
        int n = startTime.size();
        int maxTime = 0;
        int maxProfit=0;
        int prevProf=0;
        for (int i=0;i<n;i++){
                Jobs[endTime[i]]=profit[i];
        }
        for(auto i =Jobs.begin();i!=Jobs.end();i++){
            maxProfit+=max(maxProfit,i->second);
            prevProf=maxProfit;
            
        }
        return maxProfit;


        
    }

};
