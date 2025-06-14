class Solution { 
    class Pair<K, V>{
        private K key;
        private V values;
        Pair(K key, V values){
            this.key = key;
            this.values = values;
        }
        K getKey(){
            return key;
        }
        V getValue(){
            return values;
        }
    }
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        //equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
        // 1) build graph where each variable is a node and division is an edge-->weight w (forward weight)
        // 2) connect back--> weight = 1/w
        // 3) DFS BFS path from start variable to the destination
        // 4) multiple weights along path else -1.0

        //Build the graph
        Map<String, List<Pair<String, Double>>> graph = new HashMap<>();
        for(int i = 0; i < equations.size(); i++) {
            List<String> eq = equations.get(i);
            String from = eq.get(0);
            String to = eq.get(1);
            double val = values[i];
            graph.putIfAbsent(from, new ArrayList<>());
            graph.putIfAbsent(to, new ArrayList<>());
            graph.get(from).add(new Pair<>(to, val)); //forward edge
            graph.get(to).add(new Pair<>(from, 1.0 / val)); //reverse edge
        }
        //resolve queries
        double[] answers = new double[queries.size()];
        for(int i = 0; i < queries.size(); i++) {
            String src = queries.get(i).get(0);
            String dst = queries.get(i).get(1);
            if (!graph.containsKey(src) || !graph.containsKey(dst)) {
                answers[i] = -1.0;
            } //if same var
            else if (src.equals(dst)) answers[i] = 1.0;
            else {
                //Otherwise we do DFS to find path
                Set<String> visited = new HashSet<>();
                answers[i] = dfs(src, dst, graph, visited, 1.0);
            }
        }
        return answers;

    }
    private double dfs(String src, String dst, 
                       Map<String, List<Pair<String, Double>>> graph, 
                       Set<String> visited, 
                       double product) {
        if (src.equals(dst)) return product;
        visited.add(src);
        for (Pair<String, Double> adj : graph.get(src)) {
            String next = adj.getKey();
            double weight = adj.getValue();
            if (!visited.contains(next)) {
                double res = dfs(next, dst, graph, visited, product * weight);
                if (res != -1.0) return res;
            }
        }
        return -1.0;
    }
}
