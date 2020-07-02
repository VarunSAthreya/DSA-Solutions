//https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/ 

/*
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true


Note:

1. You may assume that all inputs are consist of lowercase letters a-z.
2. All inputs are guaranteed to be non-empty strings.
*/

class Trie {
    private Trie children[];
    boolean isEndOfWord;

    /** Initialize your data structure here. */
    public Trie() {
        children = new Trie[26];
        isEndOfWord = false;
    }
    
    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie curr = this;
        for(char c : word.toCharArray()){
            if(curr.children[c - 'a'] == null){
                curr.children[c - 'a'] = new Trie();
            }
            curr = curr.children[c - 'a'];
        }
        curr.isEndOfWord = true;
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Trie curr = this;
        for(char c: word.toCharArray()){
            curr = curr.children[c - 'a'];
            if(curr == null)
                return false;
        }
        if(curr.isEndOfWord )
            return true;
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie curr = this;
        for(char c: prefix.toCharArray()){
            curr = curr.children[c - 'a'];
            if(curr == null)
                return false;
        }
        
        return true;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */
