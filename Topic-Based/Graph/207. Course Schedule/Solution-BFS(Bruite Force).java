import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

// 220 ms
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<ArrayList<Integer>> adjList = new ArrayList<>();

        for (int i = 0; i < numCourses; i++) {
            adjList.add(i, new ArrayList<Integer>());
        }

        for (int i = 0; i < prerequisites.length; i++) {
            int[] pair = prerequisites[i];
            ArrayList<Integer> temp = adjList.get(pair[1]);
            temp.add(pair[0]);
            adjList.set(pair[1], temp);
        }

        for (int vertex = 0; vertex < numCourses; vertex++) {
            Queue<Integer> queue = new LinkedList<>();
            HashMap<Integer, Boolean> seen = new HashMap<>();

            ArrayList<Integer> currentVertices = adjList.get(vertex);
            for (int i = 0; i < currentVertices.size(); i++) {
                queue.offer(currentVertices.get(i));
            }

            while (!queue.isEmpty()) {
                int currentVertex = queue.poll();
                seen.put(currentVertex, true);
                if (currentVertex == vertex)
                    return false;

                ArrayList<Integer> nextVertices = adjList.get(currentVertex);
                for (int i = 0; i < nextVertices.size(); i++) {
                    int nextVertex = nextVertices.get(i);
                    if (!seen.containsKey(nextVertex)) {
                        queue.offer(nextVertex);
                    }
                }
            }
        }
        return true;
    }
}
