/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func buildTree(preorder []int, inorder []int) *TreeNode {
	hash := make(map[int]int)

	for i := 0; i < len(inorder); i++ {
		hash[inorder[i]] = i
	}

	return helper(preorder, inorder, hash, 0, len(preorder)-1, 0, len(inorder)-1)
}

func helper(preorder []int, inorder []int, hash map[int]int, pstart int, pend int, istart int, iend int) *TreeNode {
	if istart > iend || pstart > pend {
		return nil
	}

	var root TreeNode
	root.Val = preorder[pstart]
	ind := hash[preorder[pstart]]
	rem := ind - istart

	root.Left = helper(preorder, inorder, hash, pstart+1, pstart+rem, istart, ind-1)
	root.Right = helper(preorder, inorder, hash, pstart+rem+1, pend, ind+1, iend)

	return &root
}
