import java.util.*;

class UnionFind {
    // Maps each variable to its parent in the union-find structure
    Map<String, String> parent = new HashMap<>();

    // Stores the weight (or ratio) of a node with respect to its parent.
    // If x -> y, then weight[x] = x / y
    Map<String, Double> weight = new HashMap<>();

    // Find function with path compression and weight update
    public String find(String x) {
        // If x is not already in the parent map, initialize it
        if (!parent.containsKey(x)) {
            parent.put(x, x);           // x is its own parent
            weight.put(x, 1.0);         // x / x = 1.0
            return x;
        }

        // If x is not its own parent, do path compression
        if (!parent.get(x).equals(x)) {
            String origParent = parent.get(x);    // Save original parent
            String root = find(origParent);       // Recursively find root

            // Path compression: directly connect x to root
            parent.put(x, root);

            // Update the weight to reflect direct connection to root
            // weight[x] = weight[x] * weight[origParent]
            weight.put(x, weight.get(x) * weight.get(origParent));
        }

        // Return root of x
        return parent.get(x);
    }

    // Union operation: connects x and y with a known ratio: x / y = value
    public void union(String x, String y, double value) {
        // Initialize x and y if not already present
        if (!parent.containsKey(x)) {
            parent.put(x, x);
            weight.put(x, 1.0);
        }
        if (!parent.containsKey(y)) {
            parent.put(y, y);
            weight.put(y, 1.0);
        }

        // Find the root parents of x and y
        String rootX = find(x);
        String rootY = find(y);

        // If already connected (same root), no need to union
        if (!rootX.equals(rootY)) {
            // Connect rootX to rootY (you can also do the reverse)
            parent.put(rootX, rootY);

            // Update weight[rootX] such that:
            // (x / rootX) * weight[rootX] = value * (y / rootY)
            // ==> weight[rootX] = (weight[y] * value) / weight[x]
            double ratio = (weight.get(y) * value) / weight.get(x);
            weight.put(rootX, ratio);
        }
    }

    // Check if x and y are connected and compute the ratio x / y
    public double isConnected(String x, String y) {
        // If either variable is not in the structure, return -1.0
        if (!parent.containsKey(x) || !parent.containsKey(y)) return -1.0;

        // Find root parents
        String rootX = find(x);
        String rootY = find(y);

        // If not connected (different components), return -1.0
        if (!rootX.equals(rootY)) return -1.0;

        // If connected: return x / y = (x / root) / (y / root) = weight[x] / weight[y]
        return weight.get(x) / weight.get(y);
    }
}