class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0, n = s.size(),ind = 0;        
        while(r < n){
            while(s[r] != ' ' && r < n) r++;
            
            ind = r--;
            while(l <= r) swap(s[l++], s[r--]);
            
            r = ind+1, l = ind+1;
        }
        
        return s;
    }
};