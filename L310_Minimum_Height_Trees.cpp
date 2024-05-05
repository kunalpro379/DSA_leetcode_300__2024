class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        unordered_map<int, vector<int>>adjList;
        for (const auto& edge: edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<int>degree(n,0);
        //storing the degree of each node

        for(const auto& [node,neighbors]: adjList){
            degree[node]=neighbors.size();
        }
        queue<int >leaves;

        //storing leaf nodes
        for(int i=0;i<n;i++){
            if(degree[i]==1){leaves.push(i);}
        }
        while(n>2){
            int numLeaves=leaves.size();
            n-=numLeaves;
            for(int i=0;i<numLeaves;i++){
                int leaf=leaves.front();
                leaves.pop();
                for(int neighbor: adjList[leaf]){
                    if(--degree[neighbor]==1){leaves.push(neighbor);}
                }
            }
        }
        vector<int>minHeightTrees;
        while(!leaves.empty()){
            minHeightTrees.push_back(leaves.front());
            leaves.pop();
        }return minHeightTrees;
        
    }
};