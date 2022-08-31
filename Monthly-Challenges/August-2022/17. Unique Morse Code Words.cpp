class Solution
{
public:
    int uniqueMorseRepresentations(vector<string> &words)
    {
        vector<string> morse = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        set<string> st;
        for (string s : words)
        {
            string res = "";
            for (char ch : s)
            {
                res += morse[ch - 'a'];
            }

            st.insert(res);
        }

        return st.size();
    }
};
