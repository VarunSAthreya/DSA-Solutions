func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}

	l := 1
	temp := root

	for temp.Left != nil {
		l++
		temp = temp.Left
	}

	r := 1
	temp = root

	for temp.Right != nil {
		l++
		temp = temp.Right
	}

	if l == r {
		return int(math.Pow(2.0, float64(l))) - 1
	}

	return 1 + countNodes(root.Left) + countNodes(root.Right)
}
