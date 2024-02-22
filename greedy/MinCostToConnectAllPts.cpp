
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <list>
using namespace std;
class Solution {
public:


    int PRIM(unordered_map<int, list<int>>& Adj, vector<vector<int>>& points) {
        int n = Adj.size();
        vector<int> Vis(n, 0);
        vector<int> minCost(n, INT_MAX);
        minCost[0] = 0;
        int totalCost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); //
        
        while (!pq.empty()) {
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            if (Vis[u]) continue;
            Vis[u] = 1;
            totalCost += w;
            for (auto v : Adj[u]) {
                int vertex = v;
                // int vertex=v.first;
                // int weight=v.second;
                int weight=0;
                if(u<points.size()&& v<points.size()){
                    weight = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]); // Corrected
                }
                else{
                    weight=INT_MAX;
                }


                if (!Vis[vertex] && weight < minCost[vertex]) {
                    minCost[vertex] = weight;
                    pq.push({weight, vertex});
                }
            }
        }
        return totalCost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        //creating adjacency list 
        if(points.empty())  return 0;
        unordered_map<int, list<int>> Adj;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) { // Start from i + 1 to avoid self-loops
                int u = i;
                int v = j;
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]); // Corrected

                Adj[u].push_back(v);
                Adj[v].push_back(u);

            }
        }
        return PRIM(Adj, points); 
    }
};