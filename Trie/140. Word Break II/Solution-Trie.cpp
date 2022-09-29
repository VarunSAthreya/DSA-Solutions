//! Implemented Trie
class Trie
{
    class TrieNode
    {
    public:
        unordered_map<char, TrieNode *> edges;
        bool isEnd;
        TrieNode()
        {
            isEnd = false;
        }
    };

    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string s)
    {
        auto curr = root;
        for (char ch : s)
        {
            if (!curr->edges.count(ch))
                curr->edges[ch] = new TrieNode();

            curr = curr->edges[ch];
        }

        curr->isEnd = true;
    }

    bool search(string s)
    {
        auto curr = root;
        for (char ch : s)
        {
            if (!curr->edges.count(ch))
                return false;

            curr = curr->edges[ch];
        }

        return curr->isEnd;
    }
};
//! Trie ends

class Solution // Solution Starts
{
private:
    Trie *trie = new Trie();

    void solve(const string &s, string st, int ind, vector<string> &res)
    {
        if (ind == s.size())
        {
            res.push_back(st);
            return;
        }

        if (ind != 0)
            st += " ";

        for (int i = ind; i < s.size(); i++)
        {
            if (trie->search(s.substr(ind, i + 1 - ind)))
            {
                solve(s, st + s.substr(ind, i + 1 - ind), i + 1, res);
            }
        }
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        for (string word : wordDict)
            trie->insert(word);

        vector<string> res;
        solve(s, "", 0, res);

        return res;
    }
};
