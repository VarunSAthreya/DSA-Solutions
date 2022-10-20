class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(26,0);
        for(auto c: t) map[c-'a']++;

        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;

        while(end<s.size()){
            if(map[s[end++]-'a']-->0) counter--; //in t

            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]-'a']++==0) counter++;  //make it invalid
            }  
        }

        return d == INT_MAX ? "" : s.substr(head, d);
    }
};