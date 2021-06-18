class StreamChecker {

    StringBuilder sb;
    TrieNode root;

    // reverse to store the stream and reverse the whole stringbuilder to do the
    // query
    public StreamChecker(String[] words) {
        sb = new StringBuilder();
        root = new TrieNode();
        createTrie(words);
    }

    public boolean query(char letter) {
        sb.append(letter);
        TrieNode node = root;
        for (int i = sb.length() - 1; i >= 0 && node != null; i--) {
            char ch = sb.charAt(i);
            node = node.next[ch - 'a'];
            if (node != null && node.isWord)
                return true;
        }
        return false;
    }

    private void createTrie(String[] words) {
        for (String s : words) {
            TrieNode node = root;
            int N = s.length();
            for (int i = N - 1; i >= 0; i--) {
                char ch = s.charAt(i);
                if (node.next[ch - 'a'] == null)
                    node.next[ch - 'a'] = new TrieNode();
                node = node.next[ch - 'a'];
            }
            node.isWord = true;
        }
    }
}

class TrieNode {
    boolean isWord;
    TrieNode[] next = new TrieNode[26];
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker obj = new StreamChecker(words); boolean param_1 =
 * obj.query(letter);
 */