class Solution {
    List<List<Integer>> result;

    // i = 3
    // [1,1,0,0]
    // <0, 1,3>
    // <0,2,

    public void bfs(int[][] graph, List<Integer> output1, int i) {
        List<Integer> output = new ArrayList<>(output1);
        if (i == graph.length - 1) {
            output.add(i);
            result.add(output);
            return;
        }
        // if(visited[i] == 1)
        // return;
        // visited[i] = 1;
        output.add(i);
        for (int t : graph[i]) {
            bfs(graph, output, t);
        }
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int n = graph.length;
        if (n <= 1) {
            return null;
        }

        result = new ArrayList<>();
        // int[] visited = new int[n];

        bfs(graph, new ArrayList<>(), 0);

        return result;
    }
}