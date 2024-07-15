class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> Adj(n); // Adjacency list

        // Build the adjacency list
        for (auto &road : roads)
        {
            int city1 = road[0], city2 = road[1];
            int importance = city1 + city2;
            Adj[city1].push_back({city2, importance});
            Adj[city2].push_back({city1, importance});
        }

        // Priority queue to store roads by their importance
        priority_queue<pair<int, pair<int, int>>> maxHeap;

        // Push all roads into the heap
        for (int i = 0; i < n; ++i)
        {
            for (auto &neighbor : Adj[i])
            {
                int city1 = i, city2 = neighbor.first, importance = neighbor.second;
                maxHeap.push({importance, {city1, city2}});
            }
        }

        // Assign values 1 to n to cities
        vector<int> vals(n, -1); // -1 means not assigned yet
        for (int i = 0; i < n; ++i)
        {
            vals[i] = i + 1; // Assigning cities values from 1 to n
        }

        // Calculate the maximum total importance
        long long totalImportance = 0;
        while (!maxHeap.empty())
        {
            auto [importance, cities] = maxHeap.top();
            maxHeap.pop();
            int city1 = cities.first, city2 = cities.second;
            if (vals[city1] == -1 && vals[city2] == -1)
            {
                totalImportance += importance;
                vals[city1] = city1 + 1;
                vals[city2] = city2 + 1;
            }
        }

        return totalImportance;
    }
};
