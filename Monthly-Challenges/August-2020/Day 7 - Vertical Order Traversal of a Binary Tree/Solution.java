
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    List<int[]> list = new ArrayList<>();

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        DFS(root, 0, 0);

        list.sort(new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if (a[1] != b[1]) {
                    // sort based on X
                    return a[1] - b[1];
                } else if (a[2] != b[2]) {
                    // then Y, decreasing order
                    return -a[2] + b[2];
                } else {
                    // then value
                    return a[0] - b[0];
                }
            }
        });

        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < list.size(); i++) {
            int j = i;

            while (j < list.size() && list.get(j)[1] == list.get(i)[1]) {
                j++;
            }

            List<Integer> temp = new ArrayList<>();

            for (int z = i; z < j; z++) {
                temp.add(list.get(z)[0]);
            }

            result.add(temp);
            i = j - 1;
        }

        return result;

    }

    private void DFS(TreeNode root, int x, int y) {
        if (root == null)
            return;
        list.add(new int[] { root.val, x, y });
        DFS(root.left, x - 1, y - 1);
        DFS(root.right, x + 1, y - 1);
    }

}
