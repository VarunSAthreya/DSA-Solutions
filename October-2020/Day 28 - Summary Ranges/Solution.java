class Solution {
    public List<String> summaryRanges(int[] nums) {
        if (nums == null || nums.length == 0)
            return new ArrayList<String>();
        
        List<String> res = new ArrayList<String>();
        
        for (int i = 0; i < nums.length; i++) {
            int start = nums[i];
            while (i < nums.length - 1 && nums[i + 1] == nums[i] + 1) 
                i++;
            
            if (start != nums[i]) {
                res.add(
                    new StringBuilder()
                    .append(start)
                    .append("->")
                    .append(nums[i])
                    .toString()
                );
            } else {
                res.add(
					new StringBuilder()
					.append(start)
					.toString()
				);
            }
        }
        
        return res;
    }
}