func maxArea(height []int) int {
	i := 0
	j := len(height) - 1
	res := 0

	for i < j {
		area := (j - i)
		if height[i] > height[j] {
			area *= height[j]
			j--
		} else {
			area *= height[i]
			i++
		}
		if res < area {
			res = area
		}

	}

	return res
}
