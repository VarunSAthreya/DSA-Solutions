// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int countNodes(TreeNode root) {
        TreeNode left = root;
        TreeNode right = root;

        int heightLeft = 0;
        int heightRight = 0;

        while (left != null) {
            heightLeft++;
            left = left.left;
        }

        while (right != null) {
            heightRight++;
            right = right.right;
        }

        if (heightLeft == heightRight)
            return (1 << heightLeft) - 1; // ALT to: Math.pow(2, height) -1;

        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
