class Solution {
    class UnionFind{
        int[] parent;
        UnionFind(int n){
            parent=new int[n];
            for(int i=0;i<n;i++)parent[i]=i;
        }
        // int find(int x){
        //     if(parent[x!=x])parent[x]=find(parent[x]);
        //     return parent[x];
        // }
        // int union(int a, int b){
        //     int rootA=find(a);
        //     int rootB=find(b);
        //     if(rootA!=rootB)parent[rootB]=rootA;
        // }
        int find(int x){
            return parent[x]==x?x:(parent[x]=find(parent[x]));
        }
        void union(int a, int b){
            if(find(a)!=find(b))parent[find(b)]=find(a);
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n=isConnected.length;
        UnionFind uff=new UnionFind(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n; j++){
                if(isConnected[i][j]==1)uff.union(i,j);
            }
        }int provinces=0;
        for(int i=0;i<n;i++)if(uff.find(i)==i)provinces++;//root
        return provinces;
    }
}