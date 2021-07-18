// 1ms
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList[] graph = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++)
            graph[i] = new ArrayList();

        boolean[] visited = new boolean[numCourses];
        boolean[] dp = new boolean[numCourses];

        for (int i = 0; i < prerequisites.length; i++) {
            graph[prerequisites[i][1]].add(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(graph, i, visited, dp))
                return false;
        }
        return true;
    }

    private boolean dfs(ArrayList[] graph, int course, boolean[] visited, boolean[] dp) {
        if (visited[course])
            return dp[course];
        else
            visited[course] = true;

        for (int i = 0; i < graph[course].size(); i++) {
            if (!dfs(graph, (int) graph[course].get(i), visited, dp))
                return false;
        }
        dp[course] = true;
        return true;
    }
}
