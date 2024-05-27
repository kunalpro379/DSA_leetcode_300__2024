class Union_Find_Algo
{
public:
    unordered_map<int, int> parent; // parend node of each node
    int find(int x)
    {
        // if x is not present in the parent map
        // seet its parent to child
        if (!parent.count(x))
            parent[x] = x;
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        int rootx = find(x); // root of set containing x and y
        int rooty = find(y);
        // if x and y are not already int the same set
        // make one the parent of other
        if (rootx != rooty)
            parent[rooty] = rootx;
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        Union_Find_Algo Uf;
        vector<int> rednEdge;
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            if (Uf.find(u) == Uf.find(v))
                rednEdge = edge;
            else
                Uf.unite(u, v);
        }
        return rednEdge;
    }
};