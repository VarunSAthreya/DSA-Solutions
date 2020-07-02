class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if len(nums)<= 1:
            return 0
        for i in range(0,len(nums)):
            if nums[i]==0:
                nums[i]=-1
        d = {0:0}
        count = 0
        maxi = 0

        for i,v in enumerate(nums):
            count += v
            if count in d:
                maxi = max(maxi,i+1-d[count])
            else:
                d[count] = i+1
        return maxi
