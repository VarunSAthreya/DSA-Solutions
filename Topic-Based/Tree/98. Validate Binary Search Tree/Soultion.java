//  Definition for a binary tree node.
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
    public boolean isValidBST(TreeNode root) {
        return isValid(root, null, null);
    }

    public boolean isValid(TreeNode root, Integer minValue, Integer maxValue) {
        if (root == null)
            return true;

        if ((minValue != null && root.val <= minValue) || (maxValue != null && root.val >= maxValue)) {
            return false;
        }
        return isValid(root.left, minValue, root.val) && isValid(root.right, root.val, maxValue);
    }
}
