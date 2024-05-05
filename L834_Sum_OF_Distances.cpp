class Solution {
public:
    void DFS(int node, int parent, const vector<vector<int>>& ADJ, 
                        vector<int>& subtreeCount, vector<int>& subtreeSum) {
        for(int neighbor : ADJ[node]) {
            if(neighbor != parent) {
                DFS(neighbor, node, ADJ, subtreeCount, subtreeSum);
                subtreeCount[node] += subtreeCount[neighbor];
                subtreeSum[node] += subtreeSum[neighbor] + subtreeCount[neighbor];
            }
        }
    }

    void calculateDist(int node, int parent, const vector<vector<int>>& ADJ,
                            const vector<int>& subtreeCount, const vector<int>& subtreeSum,
                            vector<int>& answer, int n) {
        for(int neighbor : ADJ[node]) {
            if(neighbor != parent) {
                answer[neighbor] = answer[node] - subtreeCount[neighbor] + (n - subtreeCount[neighbor]);
                calculateDist(neighbor, node, ADJ, subtreeCount, subtreeSum, answer, n);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> ADJ(n);
        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            ADJ[u].push_back(v);
            ADJ[v].push_back(u);
        }

        // DFS
        vector<int> subtreeCount(n, 1);
        vector<int> subtreeSum(n, 0);

        // DFS from root
        DFS(0, -1, ADJ, subtreeCount, subtreeSum);

        vector<int> res(n); // Resize the result vector
        res[0] = subtreeSum[0];
        calculateDist(0, -1, ADJ, subtreeCount, subtreeSum, res, n);

        return res;
    }
};
