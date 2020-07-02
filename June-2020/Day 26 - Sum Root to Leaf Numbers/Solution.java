/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    int result = 0;

    public int sumNumbers(TreeNode root) {
        if (root == null)
            return 0;

        findSum(root, 0);
        return result;
    }

    void findSum(TreeNode root, int val) {
        int curr = val * 10 + root.val;
        if (root.left == null && root.right == null) {
            result += curr;
            return;
        }
        if (root.left != null)
            findSum(root.left, curr);
        if (root.right != null)
            findSum(root.right, curr);

    }

}