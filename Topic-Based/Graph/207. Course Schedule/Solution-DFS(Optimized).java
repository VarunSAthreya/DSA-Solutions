// 3ms
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<Integer>[] adjList = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adjList[i] = new ArrayList();
        }

        for (int[] pre : prerequisites) {
            adjList[pre[0]].add(pre[1]);
        }

        int[] visited = new int[numCourses];
        for (int course = 0; course < numCourses; course++) {
            if (visited[course] == 0 && !dfs(adjList, visited, course))
                return false;
        }
        return true;
    }

    private boolean dfs(ArrayList<Integer>[] graph, int[] visited, int course) {
        if (visited[course] == 1)
            return false;
        visited[course] = 1;
        for (int vertex : graph[course]) {
            if (!dfs(graph, visited, vertex))
                return false;
        }
        visited[course] = 2;

        return true;
    }
}
