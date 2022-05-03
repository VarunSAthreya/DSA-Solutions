func sortArrayByParity(nums []int) []int {
    i:=0
    for j:=0;j<len(nums);j++{
        if nums[j] %2 == 0 {
            temp:= nums[i]
            nums[i] = nums[j]
            nums[j] = temp
            i++
        }
    }
    return nums
}
