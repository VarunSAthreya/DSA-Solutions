class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int ns = s.length();
        int np = p.length();
        int[] sRef = new int[26];
        int[] pRef = new int[26];
        List<Integer> results = new ArrayList<>();

        if (ns < np) {
            return results; // No solution
        }

        // Build the reference array for p
        for (char ch : p.toCharArray()) {
            pRef[ch - 'a']++;
        }

        // Slide window and compare
        for (int i = 0; i < ns; i++) {
            sRef[s.charAt(i) - 'a']++; // Add right

            if (i >= np) {
                sRef[s.charAt(i - np) - 'a']--; // Remove from left
            }

            if (Arrays.equals(sRef, pRef)) {
                results.add((i - np) + 1);
            }
        }

        return results;
    }
}
