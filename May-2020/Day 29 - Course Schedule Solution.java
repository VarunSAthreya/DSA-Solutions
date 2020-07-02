// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/538/week-5-may-29th-may-31st/3344/

/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices.
   Read more about how a graph is represented.
2. You may assume that there are no duplicate edges in the input prerequisites.
3. 1 <= numCourses <= 10^5
*/

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        ArrayList<Integer>[] adj = new ArrayList[numCourses];
        for(int i = 0; i < numCourses; i++){
            adj[i] = new ArrayList();
        }
        
        for(int[] pre : prerequisites){
            adj[pre[0]].add(pre[1]);
        }
        
        int[] visited = new int[numCourses];
        for(int i = 0; i<numCourses; i++){
            if(visited[i] == 0 && !dfs(adj ,visited, i))
                return false;
        }
        return true;
    }
    
    private boolean dfs(ArrayList<Integer>[] adj, int[] visited, int v){
        if(visited[v] == 1)
            return false;
        visited[v] =1;
        for(int ad: adj[v]){
            if(!dfs(adj, visited, ad))
                return false;
        }
        visited[v] = 2;
        
        return true;
    }
}
