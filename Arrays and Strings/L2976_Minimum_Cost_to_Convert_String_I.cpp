class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = source.size();
        if (n != target.size())
            return -1;

        // conversion graph
        unordered_map<char, unordered_map<char, long long>> conversionGraph;
        for (int i = 0; i < original.size(); ++i)
        {
            char orig = original[i];
            char change = changed[i];
            int c = cost[i];
            if (conversionGraph[orig].find(change) == conversionGraph[orig].end() || c < conversionGraph[orig][change])
            {
                conversionGraph[orig][change] = c;
            }
        }

        auto getMinCost = [&](char src, char dest) -> long long
        {
            if (src == dest)
                return 0;
            if (conversionGraph.find(src) == conversionGraph.end())
                return INT_MAX;
            unordered_map<char, long long> minCost;
            queue<int> q;
            q.push(src);
            minCost[src] = 0;

            while (!q.empty())
            {
                char current = q.front();
                q.pop();
                for (const auto &[nextChar, conversionCost] : conversionGraph[current])
                {
                    long long newCost = minCost[current] + conversionCost;
                    if (minCost.find(nextChar) == minCost.end() || newCost < minCost[nextChar])
                    {
                        minCost[nextChar] = newCost;
                        q.push(nextChar);
                    }
                }
            }
            return minCost.find(dest) != minCost.end() ? minCost[dest] : INT_MAX;
        };
        long long totalCost = 0;
        for (int i = 0; i < n; i++)
        {
            long long cost = getMinCost(source[i], target[i]);
            if (cost == INT_MAX)
                return -1;
            totalCost += cost;
        }
        return totalCost;
    }
};