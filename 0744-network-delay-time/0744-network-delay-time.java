class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // long  inf=999999999;
        long inf =(long)1e9;
        // Integer[] dist=new Integer[n+1];
        long[] dist=new long[n+1];
        Arrays.fill(dist, inf);
        dist[k]=0;
        for(int i=1;i<n;i++){
            for(int[] edge: times){
                int u=edge[0], v=edge[1],w=edge[2];
            if(dist[u]!=inf&& dist[u]+w<dist[v])dist[v]=dist[u]+w;
            }
        }
        long maxTime=0;

        for(int i=1;i<=n;i++){
            if(dist[i]==inf)return -1;
            maxTime = Math.max(maxTime, dist[i]);
        }
        return (int)maxTime;

    }
}