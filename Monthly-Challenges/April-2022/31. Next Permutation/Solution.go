func nextPermutation(nums []int) {
	n := len(nums)
	var k int
	l := 0
	for k = n - 2; k >= 0; k-- {
		if nums[k] < nums[k+1] {
			break
		}
	}

	if k < 0 {
		reverse(&nums, 0, n-1)
	} else {
		for l = n - 1; l > k; l-- {
			if nums[l] > nums[k] {
				break
			}
		}
		nums[k], nums[l] = nums[l], nums[k]
		reverse(&nums, k+1, n-1)
	}
}

func reverse(nums *[]int, i int, j int) {
	for i < j {
		(*nums)[i], (*nums)[j] = (*nums)[j], (*nums)[i]
		i++
		j--
	}
}
