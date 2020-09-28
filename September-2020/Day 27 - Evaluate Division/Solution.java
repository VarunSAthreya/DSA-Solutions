class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, List<Pair<String, Double>>> g = buildGraph(equations, values);
        
        double[] result = new double[queries.size()];
        for(int i = 0; i < queries.size(); i++)
            result[i] = dfs(queries.get(i).get(0), queries.get(i).get(1), new HashSet(), g);
        
        return result;
    }
    
    private double dfs(String s, String d, Set<String> visited, Map<String, List<Pair<String, Double>>> g) {
        if(!(g.containsKey(s) && g.containsKey(d)))
            return -1.0;
        if(s.equals(d))
            return 1.0;
        
        visited.add(s);
        for(Pair<String, Double> ng : g.get(s)) {
            if(!visited.contains(ng.getKey())) {
                double ans = dfs(ng.getKey(), d, visited, g);
                if(ans != -1.0)
                    return ans * ng.getValue();
            }
        }
        
        return -1.0;
    }
    
    private Map<String, List<Pair<String, Double>>> buildGraph(List<List<String>> equations, double[] values) {
        Map<String, List<Pair<String, Double>>> g = new HashMap();
        for(int i=0; i<values.length; i++) {
            String src = equations.get(i).get(0);
            String dest = equations.get(i).get(1);
            g.computeIfAbsent(src, k -> new ArrayList()).add(new Pair(dest, values[i])); 
            g.computeIfAbsent(dest, k -> new ArrayList()).add(new Pair(src, 1 / values[i]));
        }
        return g;
    }
}