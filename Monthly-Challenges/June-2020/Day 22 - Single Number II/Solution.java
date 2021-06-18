// with using extra space
class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();

        for (int i : nums) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }
        for (int i : nums) {
            if (map.get(i) == 1)
                return i;
        }
        return -1;
    }
}
// without using extra space
class Solution {
    public int singleNumber(int[] nums) {
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length ; i+=3){
            if(!(i < nums.length-2 &&nums[i] == nums[i+1] && nums[i] == nums[i+2]))
                return nums[i];
        }
        return 0;
    }
        
}
