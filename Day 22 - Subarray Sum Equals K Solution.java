class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        int cs = 0;
        int count = 0;
        
        for (int n : nums){
            cs += n;
            if(cs == k)
                count++;
            if(map.containsKey(cs-k))
                count += map.get(cs-k);
            if(map.containsKey(cs)){
                int val = map.get(cs) +1;
                map.replace(cs, val);
            }
            else
                map.put(cs, 1);
        }
        return count;
    }
}
