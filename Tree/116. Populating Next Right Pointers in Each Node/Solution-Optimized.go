func connect(root *Node) *Node {
	head := root
	for ; root != nil; root = root.Left {
		for cur := root; cur != nil; cur = cur.Next {

			if cur.Left != nil {
				cur.Left.Next = cur.Right
				if cur.Next != nil {
					cur.Right.Next = cur.Next.Left
				}
			} else {
				break
			}

		}
	}

	return head
}
