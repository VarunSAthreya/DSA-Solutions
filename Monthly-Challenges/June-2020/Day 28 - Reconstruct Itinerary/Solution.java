class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, PriorityQueue<String>> adj = new HashMap<>();
        for (List<String> t : tickets) {
            adj.putIfAbsent(t.get(0), new PriorityQueue<>());
            adj.get(t.get(0)).add(t.get(1));
        }

        LinkedList<String> result = new LinkedList<>();
        dfs(adj, result, "JFK");

        return result;

    }

    private void dfs(Map<String, PriorityQueue<String>> adj, LinkedList<String> result, String s) {
        PriorityQueue<String> pq = adj.get(s);
        while (pq != null && !pq.isEmpty()) {
            String v = pq.poll();
            dfs(adj, result, v);
        }
        result.addFirst(s);
    }
}