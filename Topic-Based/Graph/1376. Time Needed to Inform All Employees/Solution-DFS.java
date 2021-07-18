// Detailed Solution: Top-Down Approach
class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        List<ArrayList<Integer>> graph = new ArrayList<>();

        for (int i = 0; i < manager.length; i++) {
            graph.add(i, new ArrayList<Integer>());
        }
        for (int i = 0; i < manager.length; i++) {
            if (manager[i] != -1) {
                ArrayList<Integer> temp = graph.get(manager[i]);
                temp.add(i);
                graph.set(manager[i], temp);
            }
        }

        return dfs(headID, graph, informTime);
    }

    private int dfs(int currentId, List<ArrayList<Integer>> graph, int[] informTime) {
        if (graph.get(currentId).isEmpty()) {
            return 0;
        }
        int max = 0;
        ArrayList<Integer> subOrdinates = graph.get(currentId);
        for (int i = 0; i < subOrdinates.size(); i++) {
            max = Math.max(max, dfs(subOrdinates.get(i), graph, informTime));
        }
        return max + informTime[currentId];
    }
}

// Best Solution: Bottom-Up Approach

class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int res = 0;

        for (int i = 0; i < n; i++) {
            res = Math.max(res, dfs(i, manager, informTime));
        }

        return res;
    }

    public int dfs(int i, int[] manager, int[] informTime) {
        if (manager[i] != -1) {
            informTime[i] += dfs(manager[i], manager, informTime);
            manager[i] = -1;
        }

        return informTime[i];
    }
}
