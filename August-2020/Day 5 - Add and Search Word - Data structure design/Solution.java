class Trie{
    Trie[] children;

    boolean isWord;
    
    public Trie(){
        this.children = new Trie[26];

        this.isWord = false;
    }
}

class WordDictionary {
    
    Trie root;
    /** Initialize your data structure here. */
    public WordDictionary() {
        this.root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
        Trie cur = root;
        
        for (char c : word.toCharArray()) {
            if (cur.children[c - 'a'] == null) {
                cur.children[c - 'a'] = new Trie();
            }
            cur = cur.children[c - 'a'];
        }
        
        cur.isWord = true;
        
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(Trie cur, String word, int i) {
        if (i == word.length() ) {
            return cur.isWord;
        }
            char c = word.charAt(i);
            
            if (c == '.') {
                for (Trie child: cur.children) {
                    if (child != null && search(child, word, i + 1)) {
                        return true;
                    }
                }
                return false;
            }else{
                
                if (cur.children[c - 'a'] != null && search(cur.children[c - 'a'], word, i + 1)) {
                    return true;
                }
            }

        return false;
    }
    
    public boolean search(String word) {
        
        
        return search(root, word, 0);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */