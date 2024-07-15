/*
class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        //-1--> uncolored ||0--> color A || 1--> color B
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                queue<int>Q;
                Q.push(i);
                color[i]=0;
                while(!Q.empty()){
                    int node=Q.front();
                    Q.pop();
                    for(int neighbour:graph[node]){
                        if(color[neighbour]==-1){
                            color[neighbour]=1-color[node];
                            Q.push(neighbour);
                        }else if(color[neighbour]==color[node]){
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }



};
*/
class UnionFind
{
public:
    vector<int> parent; // array to keep track of the parent of each node
    vector<int> rank;   // array to keep track of the rank
    // contructor
    UnionFind(int size)
    {
        parent = vector<int>(size);  // initialize parennt array
        rank = vector<int>(size, 0); // initialize rank array with zeroes

        for (int i = 0; i < size; i++)
        {
            parent[i] = i; // each node is its own parent initially
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // reccurssively find the root
        }
        return parent[x];
    }
    void unionSets(int x, int y)
    {
        int rootX = find(x); // root of set containing x
        int rootY = find(y); // root of set containing y
        if (rootX != rootY)
        { // only union if they are in different sets
            if (rank[rootX] > rank[rootY])
            { // attatch smaller tre eunder root of larger tree
                parent[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            { // attatch smaller tree under root of larger tree
                parent[rootX] = rootY;
            }
            else
            {
                parent[rootY] = rootX; // arbitrarily choose one as root andnincrease rank
                rank[rootX]++;
            }
        }
    }
};
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size(); // no. of nodes in graph
        UnionFind uf(2 * n);  // handling 2 sets so 2n elements
        for (int u = 0; u < n; u++)
        { // iterating over each node u
            for (int v : graph[u])
            { // iterating over each neighbour v off u
                if (uf.find(u) == uf.find(v))
                    return false; // check if u and v are in same set
                // if yes then ofc grapj is not bipartite
                uf.unionSets(u, v + n);
                uf.unionSets(v, u + n);
            }
        }
        return true;
    }
};