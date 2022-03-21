func buildTree(inorder []int, postorder []int) *TreeNode {
	hash := make(map[int]int)
	for i := 0; i < len(inorder); i++ {
		hash[inorder[i]] = i
	}

	return helper(inorder, postorder, hash, 0, len(inorder)-1, 0, len(postorder)-1)
}

func helper(inorder []int, postorder []int, hash map[int]int, istart int, iend int, pstart int, pend int) *TreeNode {
	if pstart > pend || istart > iend {
		return nil
	}

	var root TreeNode
	ind := hash[postorder[pend]]

	root.Val = postorder[pend]

	root.Left = helper(inorder, postorder, hash, istart, ind-1, pstart, pstart+ind-istart-1)
	root.Right = helper(inorder, postorder, hash, ind+1, iend, pstart+ind-istart, pend-1)

	return &root
}
