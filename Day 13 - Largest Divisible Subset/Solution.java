class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        int n = nums.length;
        List<Integer> result = new ArrayList<>();
        if(n == 0) return result;
        Arrays.sort(nums);
        
        int[] next_idx = new int[n];
        int[] sizes = new int[n];
        Arrays.fill(next_idx, -1);
        Arrays.fill(sizes, 1);
        int max_len = 1;
        int max_idx = 0;
        
        for(int i = n-1; i >= 0; i--){
            int j = i + 1;
            int _max = 0;
            int _max_idx = i;
            while(j < n){
                if(nums[j] % nums[i] == 0 && sizes[j] > _max){
                    _max = sizes[j];
                    _max_idx = j;
                }
                j++;
            }
            if(_max_idx != i){
                sizes[i] += sizes[_max_idx];
                next_idx[i] = _max_idx;
                if(_max + 1  > max_len){
                    max_len = _max + 1;
                    max_idx = i;
                }
            }
        }
        int curr = max_idx;
        while(curr >= 0){
            result.add(nums[curr]);
            curr = next_idx[curr];
        }
        return result;
     }
}