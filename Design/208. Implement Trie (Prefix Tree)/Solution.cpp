class Trie
{

private:
    class TrieNode
    {
    public:
        map<char, TrieNode *> edges;
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

    void insert(string word)
    {
        auto curr = root;
        for (char ch : word)
        {
            if (!curr->edges.count(ch))
            {
                curr->edges[ch] = new TrieNode();
            }
            curr = curr->edges[ch];
        }
        curr->isEnd = true;
    }

    bool search(string word)
    {
        auto curr = root;
        for (char ch : word)
        {
            if (!curr->edges.count(ch))
                return false;

            curr = curr->edges[ch];
        }
        return curr->isEnd;
    }

    bool startsWith(string prefix)
    {
        auto curr = root;
        for (char ch : prefix)
        {
            if (!curr->edges.count(ch))
                return false;

            curr = curr->edges[ch];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
