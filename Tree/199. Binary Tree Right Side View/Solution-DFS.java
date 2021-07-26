// Definition for a binary tree node.
public class TreeNode {
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();

        rightSide(root, result, 0);
        return result;
    }

    public void rightSide(TreeNode root, List<Integer> result, int depth) {
        // Using preorder traversal with changes of NRL i.e first executing right child
        // as we need to find the rightmost value

        if (root == null)
            return;
        if (depth >= result.size())
            result.add(root.val);
        if (root.right != null)
            rightSide(root.right, result, depth + 1);
        if (root.left != null)
            rightSide(root.left, result, depth + 1);
    }
}
