
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */

class Solution {
    public boolean isCousins(TreeNode root, int x, int y) {
        AtomicInteger p1 = new AtomicInteger();
        AtomicInteger p2 = new AtomicInteger();
        AtomicInteger d1 = new AtomicInteger(-1);
        AtomicInteger d2 = new AtomicInteger(-1);
        findParentAndDepth(root, x, y, 0, d1, d2, p1, p2);
        return ((d1.get() == d2.get()) && (p1.get() != p2.get()));
    }

    void findParentAndDepth(TreeNode root, int x, int y, int d, AtomicInteger d1, AtomicInteger d2, AtomicInteger p1,
            AtomicInteger p2) {
        if (root == null)
            return;
        if (root.left != null) {
            if (root.left.val == x) {
                p1.set(root.val);
                d1.set(d + 1);
            } else if (root.left.val == y) {
                p2.set(root.val);
                d2.set(d + 1);
            }
        }
        if (root.right != null) {
            if (root.right.val == x) {
                p1.set(root.val);
                d1.set(d + 1);
            } else if (root.right.val == y) {
                p2.set(root.val);
                d2.set(d + 1);
            }
        }
        if (d1.get() != -1 && d2.get() != -1)
            return;
        findParentAndDepth(root.left, x, y, d + 1, d1, d2, p1, p2);
        findParentAndDepth(root.right, x, y, d + 1, d1, d2, p1, p2);
    }
}
