/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.
Example 1:
https://assets.leetcode.com/uploads/2019/10/15/untitled-diagram-2.jpg
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:
https://assets.leetcode.com/uploads/2019/10/09/untitled-diagram-1.jpg
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false 

Constraints:

1. 2 <= coordinates.length <= 1000
2. coordinates[i].length == 2
3. -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
4. coordinates contains no duplicate point.
*/

class Solution {
    public boolean checkStraightLine(int[][] cord) {
        float m = getSlope(cord[0], cord[1]);
        for(int i=2 ;i<cord.length; i++){
            float slope = getSlope(cord[i], cord[0]);
            if(slope != m)
                return false;
        }
        return true;
    }
    float getSlope(int[] p1, int[] p2){
        if(p1[0] == p2[0])
            return Float.MAX_VALUE;
        return(float)(p2[1]-p1[1])/(p2[0]-p1[0]);
    } 
}
