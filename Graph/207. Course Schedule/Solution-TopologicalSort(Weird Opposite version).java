import java.util.ArrayList;
import java.util.List;

// Opposite version on Topology sort (Works but not sure why)
// 133 ms
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        if (prerequisites == null || prerequisites.length == 0)
            return true;

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

        // get indexes of course whose is pre-course of no course
        // i.e its the last course
        ArrayList<Integer> noPreCourse = getZeroCourse(adjList);
        int count = 0;

        // removing the last course and then its value in its pre-course list
        while (!noPreCourse.isEmpty()) {
            for (Integer integer : noPreCourse) {
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(-1);
                adjList.set(integer, temp);
                removeValue(adjList, integer);
                count++;
            }
            noPreCourse = getZeroCourse(adjList);
        }

        return count == numCourses;
    }

    private ArrayList<Integer> getZeroCourse(List<ArrayList<Integer>> adjList) {
        ArrayList<Integer> index = new ArrayList<>();
        for (int i = 0; i < adjList.size(); i++) {
            if (adjList.get(i).isEmpty())
                index.add(i);
        }
        return index;
    }

    private void removeValue(List<ArrayList<Integer>> adjList, Integer target) {
        for (ArrayList<Integer> arrayList : adjList) {
            if (arrayList.contains(target)) {
                arrayList.remove(target);
            }
        }
    }
}
