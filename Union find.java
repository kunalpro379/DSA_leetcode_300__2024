class UnionFind {
    Map<String, String> parent = new HashMap<>();
    Map<String, Double> weight = new HashMap<>(); // x / parent[x]

    public String find(String x) {
        if (!parent.containsKey(x)) {
            parent.put(x, x);
            weight.put(x, 1.0);
            return x;
        }

        if (!parent.get(x).equals(x)) {
            String origParent = parent.get(x);
            String root = find(origParent);

            // path compression with weight update
            weight.put(x, weight.get(x) * weight.get(origParent));
            parent.put(x, root);
        }

        return parent.get(x);
    }

    public void union(String x, String y, double value) {
        if (!parent.containsKey(x)) {
            parent.put(x, x);
            weight.put(x, 1.0);
        }
        if (!parent.containsKey(y)) {
            parent.put(y, y);
            weight.put(y, 1.0);
        }

        String rootX = find(x);
        String rootY = find(y);

        if (!rootX.equals(rootY)) {
            // connect rootX to rootY
            parent.put(rootX, rootY);

            // update weight:
            // weight[rootX] * value = weight[y] / weight[x]
            double ratio = (weight.get(y) * value) / weight.get(x);
            weight.put(rootX, ratio);
        }
    }

    public double isConnected(String x, String y) {
        if (!parent.containsKey(x) || !parent.containsKey(y)) return -1.0;

        String rootX = find(x);
        String rootY = find(y);

        if (!rootX.equals(rootY)) return -1.0;

        // a / b = (a / parent[a]) / (b / parent[b])
        return weight.get(x) / weight.get(y);
    }
}