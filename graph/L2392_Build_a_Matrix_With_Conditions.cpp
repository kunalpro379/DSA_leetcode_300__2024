class Solution
{
public:
    vector<int> topologicalSort(int k, vector<vector<int>> &condition)
    {
        vector<int> inDeg(k + 1, 0);           // in degree of each node
        unordered_map<int, vector<int>> graph; // adjancy list
        // build the graph //in dgrees
        for (auto &cond : condition)
        {
            int u = cond[0], v = cond[1];
            graph[u].push_back(v);
            inDeg[v]++;
        }
        queue<int> Que;
        // add the nodes with 0 indegree to the queue
        for (int i = 1; i <= k; i++)
            if (inDeg[i] == 0)
                Que.push(i);

        vector<int> order;
        while (!Que.empty())
        {
            int node = Que.front();
            Que.pop();
            order.push_back(node);
            for (int neighbor : graph[node])
            {
                inDeg[neighbor]--;
                if (inDeg[neighbor] == 0)
                    Que.push(neighbor);
            }
        }
        if (order.size() != k)
            return {}; // check if topo sort possible ?
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);
        if (rowOrder.empty() || colOrder.empty())
            return {};
        unordered_map<int, int> rowIndex, colIndex;
        // map to get the index of each no. in the row and col order

        for (int i = 0; i < k; i++)
        {
            rowIndex[rowOrder[i]] = i; // map each no. to its row index
            colIndex[colOrder[i]] = i; // col index
        }
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        // mnow placing each number in its position based on row and cols
        for (int i = 1; i <= k; i++)
        {
            int r = rowIndex[i];
            int c = colIndex[i];
            matrix[r][c] = i;
        }
        return matrix;
    }
};