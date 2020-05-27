// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3342/

/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1. 1 <= N <= 2000
2. 0 <= dislikes.length <= 10000
3. 1 <= dislikes[i][j] <= N
4. dislikes[i][0] < dislikes[i][1]
5. There does not exist i != j for which dislikes[i] == dislikes[j].
*/

class Solution {
    public boolean possibleBipartition(int N, int[][] dislikes) {
        if(dislikes.length < 2)
            return true;
       int [] groups = new int[N];
        Arrays.fill(groups, -1);
        ArrayList<Integer>[] adj = new ArrayList[N];
        for(int i = 0; i < N; i++)
            adj[i] = new ArrayList();
        for(int [] p : dislikes){
            adj[p[0] -1].add(p[1] - 1);
            adj[p[1] -1].add(p[0] - 1);
        }
        for(int i = 0; i < N; i++){
            if(groups[i] == -1 && !dfs(adj, groups, i ,0))
                return false;
        }
        return true;
    }
    
    private boolean dfs(ArrayList<Integer>[] adj, int [] groups, int v, int grp){
        if(groups[v] == -1) groups[v] = grp;
        else 
            return groups[v] == grp;
        for(int n : adj[v]){
            if(!dfs(adj, groups, n, 1 - grp))
                return false;
        }
        return true;
    } 
}
