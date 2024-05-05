class Solution {
public:
    //#using bfs and dfs
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        //#bfs 
        vector<vector<int>>graph(n);
        for(const auto & edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(n,false);
        queue<int>Q;

        Q.push(source);
        visited[source]=true;
            while(!Q.empty()){
                int node=Q.front();
                Q.pop();
                if(node==destination)return true;
                for(int neighbor: graph[node]){
                    if(!visited[neighbor]){
                        Q.push(neighbor);
                        visited[neighbor]=true;
                    }
                }
            }
        return false;
    }
};