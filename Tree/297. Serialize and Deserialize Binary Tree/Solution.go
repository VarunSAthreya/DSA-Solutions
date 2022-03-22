/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {

	if root == nil {
		return ""
	}

	queue := []*TreeNode{root}
	c := []string{strconv.Itoa(root.Val)}

	for len(queue) > 0 {
		l := len(queue)
		for i := 0; i < l; i++ {
			if queue[i].Left != nil {
				queue = append(queue, queue[i].Left)
			}
			if queue[i].Right != nil {
				queue = append(queue, queue[i].Right)
			}
			add(&c, queue[i].Left)
			add(&c, queue[i].Right)
		}
		queue = queue[l:]
	}

	res := strings.Join(c, ",")
	return res
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(data string) *TreeNode {
	c := strings.Split(data, ",")

	if len(data) == 0 {
		return nil
	}

	t := &TreeNode{Val: myAtoi(c[0])}
	queue := []*TreeNode{t}

	i := 1
	for len(queue) > 0 {
		l := len(queue)
		for j := 0; j < l; j++ {
			if c[i] == "nil" {
				queue[j].Left = nil
			} else {
				queue[j].Left = &TreeNode{Val: myAtoi(c[i])}
				queue = append(queue, queue[j].Left)
			}
			i++
			if c[i] == "nil" {
				queue[j].Right = nil
			} else {
				queue[j].Right = &TreeNode{Val: myAtoi(c[i])}
				queue = append(queue, queue[j].Right)
			}
			i++
		}
		queue = queue[l:]
	}
	return t
}

func add(c *[]string, node *TreeNode) {
	if node == nil {
		*c = append(*c, "nil")
	} else {
		*c = append(*c, strconv.Itoa(node.Val))
	}
}

func myAtoi(s string) int {
	a, err := strconv.Atoi(s)
	if err != nil {
		panic(a)
	}
	return a
}

/**
 * Your Codec object will be instantiated and called as such:
 * ser := Constructor();
 * deser := Constructor();
 * data := ser.serialize(root);
 * ans := deser.deserialize(data);
 */
