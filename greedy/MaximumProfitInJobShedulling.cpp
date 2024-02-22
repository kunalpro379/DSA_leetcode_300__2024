#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
//method 1
class Solution1 {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> jobs;  

        for (int i = 0; i < startTime.size(); ++i) {
            jobs[endTime[i]] = max(jobs[endTime[i]], profit[i]);
        }

        int maxProfit = 0;
        int prevProf = 0;

        for (auto it = jobs.begin(); it != jobs.end(); ++it) {
            maxProfit = max(maxProfit, prevProf + it->second);
            prevProf = maxProfit;
        }

        return maxProfit;



    }


    };
    //method 2
class Solution2 {
public:
    int n;

    int getNextInd(vector<vector<int>>& array, int l, int currJobEnd) {
        int r = n - 1;
        int result = n + 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (array[mid][0] >= currJobEnd) { // Take this job
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>& array, int i) {
        if (i >= n) {
            return 0;
        }
        int next = getNextInd(array, i + 1, array[i][1]);
        int taken = array[i][2] + solve(array, next);
        int skip = solve(array, i + 1);
        return max(taken, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> array(n, vector<int>(3, 0)); // {s,e,prof}
        for (int i = 0; i < n; i++) {
            array[i][0] = startTime[i];
            array[i][1] = endTime[i];
            array[i][2] = profit[i];
        }
        // Sorting based on start time
        auto comp = [&](auto& vec1, auto& vec2) {
            return vec1[0] <= vec2[0];
        };
        sort(begin(array), end(array), comp);

        return solve(array, 0);
    }
};
