class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
 
 //solun 1 
        // unordered_set<int>neighbors;
        // for(const auto& edge:edges){
        //     neighbors.insert(edge[0]);
        //     neighbors.insert(edge[1]);

        // }
        // for(const auto&edge:edges){
        //     if(neighbors.count(edge[0])&& neighbors.count(edge[1]))return edge[0];
        // }return -1;
//solun 2

        unordered_set<int>centerCand;
        for(const auto& edge:edges){
            for(int i=0;i<2;i++){
                    if(!centerCand.count(edge[i]))centerCand.insert(edge[i]);
                    else return edge[i];
            }
        }return -1;
    }
};