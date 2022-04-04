func swapNodes(head *ListNode, k int) *ListNode {
	rep := head

	count := 1
	start := head
	last := head
	for rep != nil {
		if count == k {
			start = rep
		}
		if count > k {
			last = last.Next
		}
		count++
		rep = rep.Next
	}
	start.Val, last.Val = last.Val, start.Val

	return head
}
