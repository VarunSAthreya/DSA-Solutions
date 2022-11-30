class Solution
{
public:
    set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int vowelCount(string s) {
        int cnt = 0;
        for (char ch : s)
            if (st.find(ch) != st.end()) cnt++;

        return cnt;
    }
    
    bool halvesAreAlike(string s) {
        return vowelCount(s.substr(0, s.size() / 2)) == vowelCount(s.substr(s.size() / 2));
    }
};
