/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    List<Integer> all = new ArrayList<>();

    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        search(root1);
        search(root2);
        Collections.sort(all);
        return all;
    }

    public void search(TreeNode node) {
        if (node == null)
            return;
        if (node.left != null)
            search(node.left);
        all.add(node.val);
        if (node.right != null)
            search(node.right);
    }
}