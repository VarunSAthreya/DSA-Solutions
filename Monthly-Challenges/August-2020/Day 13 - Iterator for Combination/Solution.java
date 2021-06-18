class CombinationIterator {
    private String chars;
    private int[] pos;
    private boolean hasNext;

    public CombinationIterator(String characters, int combinationLength) {
        hasNext = true;
        chars = characters;
        pos = new int[combinationLength];
        for (int i = 0; i < combinationLength; i++) {
            pos[i] = i;
        }
    }

    public String next() {
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < pos.length; i++) {
            b.append(chars.charAt(pos[i]));
        }

        int n = chars.length();
        hasNext = false;
        for (int i = pos.length - 1; i >= 0; i--) {
            if (n - pos[i] > pos.length - i) {
                pos[i]++;
                for (int j = i + 1; j < pos.length; j++) {
                    pos[j] = pos[j - 1] + 1;
                }
                hasNext = true;
                break;
            }
        }

        return b.toString();
    }

    public boolean hasNext() {
        return hasNext;
    }
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator obj = new CombinationIterator(characters,
 * combinationLength); String param_1 = obj.next(); boolean param_2 =
 * obj.hasNext();
 */
