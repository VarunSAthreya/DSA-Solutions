func flatten(root *TreeNode) {
	cur := root

	for cur != nil {
		if cur.Left != nil {
			pre := cur.Left
			for pre.Right != nil {
				pre = pre.Right
			}
			pre.Right = cur.Right
			cur.Right = cur.Left
			cur.Left = nil
		}
		cur = cur.Right
	}
}
