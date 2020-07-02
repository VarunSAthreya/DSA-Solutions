// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/537/week-4-may-22nd-may-28th/3339/

/*
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

https://assets.leetcode.com/uploads/2019/03/06/1266.png
 

Constraints:

1. 1 <= preorder.length <= 100
2. 1 <= preorder[i] <= 10^8
3. The values of preorder are distinct.
*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
     int i = 0;
    public TreeNode bstFromPreorder(int[] preorder) {
        return bstFromPreorder(preorder, Integer.MAX_VALUE);        
    }
    public TreeNode bstFromPreorder(int[] A, int bound) {
        if (i == A.length || A[i] > bound) return null;
        TreeNode root = new TreeNode(A[i++]);
        root.left = bstFromPreorder(A, root.val);
        root.right = bstFromPreorder(A, bound);
        return root;
    }
}
