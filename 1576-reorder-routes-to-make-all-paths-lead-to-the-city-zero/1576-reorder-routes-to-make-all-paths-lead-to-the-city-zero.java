class Solution {
    List<List<int[]>>adj;
    public int minReorder(int n, int[][] connections) {
        adj=new ArrayList<>();
        for(int i=0;i<n;i++)adj.add(new ArrayList<>());
        for(int[] conn: connections){
            int a= conn[0],b=conn[1];
            adj.get(a).add(new int[] {b,1});
            adj.get(b).add(new int[] {a,0});
        }boolean[] visited=new boolean[n];
        return dfs(0,visited);
    }
    private int dfs(int node, boolean[] visited){
        visited[node]=true;
        int change=0;
        for(int[] adjNode: adj.get(node)){
            int neighbor=adjNode[0];
            int cost=adjNode[1];
            if(visited[neighbor])continue;
            change+=cost+dfs(neighbor, visited);
        }return change;
    }
}