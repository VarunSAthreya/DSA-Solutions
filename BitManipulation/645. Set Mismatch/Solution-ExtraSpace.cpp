class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> m(n+1, 0);
        for(int i:nums) m[i]++;

        vector<int> res(2,0);
        for(int i=1;i<=n;i++){
            if(m[i] == 0) res[1] = i;
            if(m[i] == 2) res[0] = i;
            if(res[0] != 0 && res[1] != 0) break;
        }

        return res;
    }
};