class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        int[] parent = new int[n];
        boolean[] hasParent = new boolean[n];

        // Step 1: Initialize each node to be its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Step 2: Union and validate
        for (int i = 0; i < n; i++) {
            int[] children = {leftChild[i], rightChild[i]};

            for (int child : children) {
                if (child == -1) continue;

                // Each node should have only one parent
                if (hasParent[child]) return false;

                hasParent[child] = true;

                // If i and child are already connected (same root), a cycle is present
                if (!union(parent, i, child)) return false;
            }
        }

        // Step 3: Check that there's exactly one root (node with no parent)
        int rootCount = 0;
        for (int i = 0; i < n; i++) {
            if (!hasParent[i]) rootCount++;
        }

        return rootCount == 1;
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
