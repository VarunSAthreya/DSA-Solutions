var prev *TreeNode

// Added extra argument num in the function
// Added because prev is present above the main function so as its a pointer it would contain date of the previous execution, to avoid this an if clause is added

func flatten(root *TreeNode, num ...int) {
	if root == nil {
		return
	}
	// Added check if its the first entry to the function
	if len(num) == 0 {
		prev = nil

	}

	flatten(root.Right, 1)
	flatten(root.Left, 1)

	root.Right = prev
	root.Left = nil

	prev = root
}
