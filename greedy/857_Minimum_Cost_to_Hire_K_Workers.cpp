class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        //greedy approach
        int n=quality.size();
        vector<pair<double, int>>ratio;
        for(int i=0;i<n;i++){
            // ratio.push_back({(double)(wage[i]/quality[i]),quality[i]});
            ratio.push_back({static_cast<double>(wage[i]) / quality[i], quality[i]});

        }
        sort(ratio.begin(), ratio.end());
        double minCost=1e9;
        int totalQuality=0;
        priority_queue<int>PQ;
        for(auto r:ratio){
            totalQuality+=r.second;
            PQ.push(r.second);
            if(PQ.size()>k){
                totalQuality-=PQ.top();
                PQ.pop();
            }
            if(PQ.size()==k){
                minCost=min(minCost,totalQuality*r.first);
            }
        }return minCost;

    }
};