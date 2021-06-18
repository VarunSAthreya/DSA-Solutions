/**
 * Definition for a binary traee node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    int result = 0;
    int count = 0;

    public int kthSmallest(TreeNode root, int k) {
        count = k;
        kthFinder(root);
        return result;
    }

    void kthFinder(TreeNode root) {
        if (root.left != null)
            kthFinder(root.left);
        count--;
        if (count == 0) {
            result = root.val;
            return;
        }
        if (root.right != null)
            kthFinder(root.right);
    }
}
