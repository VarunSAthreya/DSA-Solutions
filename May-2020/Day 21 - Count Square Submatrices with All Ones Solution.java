// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3336/

/*
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 */
 
 class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int [] counts = new int[n];
        int topleft = 0;
        int result = 0;
        for(int i = 0; i< m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 1){
                    int top = (i == 0) ? 0 : counts[j];
                    int left = (j == 0) ? 0 : counts[j-1];
                    counts[j] = 1 + Math.min(top, Math.min(left, topleft));
                    result += counts[j];
                
                    topleft = (j == n-1) ? 0 : top;
                }else
                    counts[j] = 0;                
            }
            
        }
        return result;
    }
}
