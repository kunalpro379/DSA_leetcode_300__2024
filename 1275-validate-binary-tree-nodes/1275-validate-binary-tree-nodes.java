class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] parent=new int[n];
        boolean[] hasParent=new boolean[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    //Union 
    for(int i=0;i<n;i++){
        int[]children={leftChild[i], rightChild[i]};
        for(int child: children){
            if(child==-1)continue;
            // each node should have single parent
            if(hasParent[child])return false;
            hasParent[child]=true;
            if(!union(parent, i,child))return false;
            }
        
        }
        int rootcnt=0;
        for(int i =0;i<n;i++)if(!hasParent[i])rootcnt++;
        return rootcnt==1;
    }
        private int find(int[] parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]); // path compression
        }
        return parent[x];
    }

    private boolean union(int[] parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        if (rootX == rootY) return false; // cycle detected
        parent[rootY] = rootX;
        return true;
    }
}