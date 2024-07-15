class Solution
{
public: /*
     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int, int>>>graph(n);//adjacency list
         for(const auto &flight: flights){
             int u=flight[0], v=flight[1], w=flight[2];
             graph[].emplace_back(v,w);
         }
         //prority q  (cost current_city stops)
         priority_queue<tuple<int, int, int>, vector<tuple<int , int, int >>,greater<>>pq;
         pq.emplace_back(0,src, 0);
         unordered_map<int, int >visited;
         while(!pq.empty()){
             auto [cost, city, stops]=pq.top();
             pq.top();

             if(city==dist&& stops<=k+1) return cost;

             if(stops<=k){
                 for(const auto& [next_city,price]:graph[city]){
                             int new_cost=cost+price;
                             if(visited.find()==visited.end()){}
                 }
             }
         }
         return -1;
     }
     */
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> dp(k + 2, vector<int>(n, INT_MAX));
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            dp[0][src] = 0; // corst to reach src ->0
            for (const auto &flight : flights)
            {
                int u = flight[0], v = flight[1], w = flight[2];
                if (dp[i - 1][u] != INT_MAX)
                {
                    dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
                }
            }
        }
        int minCost = INT_MAX;
        for (int i = 1; i <= k + 1; i++)
        {
            minCost = min(minCost, dp[i][dst]);
        }
        return minCost == INT_MAX ? -1 : minCost;
    }
};